"""Zero-token template tier of the matching swarm.

The idea (see notes): most trivial functions don't need an LLM at all. We
disassemble the target, recognise a small set of self-contained *shapes*
(constant returns, field load/store, two-arg arithmetic), emit the obvious C,
and let the existing match.py oracle (compile with mwccarm + relocation-aware
byte-diff) confirm it. Every function cleared here costs **zero tokens**.

Deliberately reloc-FREE only. A template that leaned on a relocation slot (e.g.
a tail-call wrapper `b somefunc`) would "match" via the reloc wildcard without
us knowing the real callee -- a false positive. So we only emit shapes whose
bytes are fully determined by the C, where a match is genuinely conclusive.

Usage:
    python tools/swarm.py                      # dry-run, report free coverage
    python tools/swarm.py --apply              # also append wins to matched.jsonl
    python tools/swarm.py --min 0x8 --max 0x40 --count 500
"""
import argparse
import io
import json
import pathlib
import re
import sys
import tempfile

from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import match as M  # reuse compile_c / extract_func / compare / target_bytes
import relocs as R  # resolve call targets / globals to symbol names

REPO = M.REPO
SYMS = REPO / "config" / "arm9" / "symbols.txt"
ARM9 = M.ARM9
BASE = M.ARM9_BASE
MATCHED = REPO / "progress" / "matched.jsonl"

md = Cs(CS_ARCH_ARM, CS_MODE_ARM)

LINE_RE = re.compile(
    r"^(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)\s+addr:0x([0-9a-fA-F]+)"
)


# ----------------------------------------------------------------------------- targets
def load_done():
    done = set()
    if MATCHED.is_file():
        for line in MATCHED.read_text(errors="ignore").splitlines():
            line = line.strip()
            if not line:
                continue
            try:
                done.add(int(json.loads(line)["addr"], 0))
            except Exception:
                pass
    return done


def enumerate_targets(lo_size, hi_size, mode, count):
    done = load_done()
    limit = BASE + ARM9.stat().st_size
    out = []
    for line in SYMS.read_text(errors="ignore").splitlines():
        m = LINE_RE.match(line)
        if not m:
            continue
        name, fmode, size_hex, addr_hex = m.groups()
        size, addr = int(size_hex, 16), int(addr_hex, 16)
        if mode != "any" and fmode != mode:
            continue
        if not (lo_size <= size <= hi_size):
            continue
        if not (BASE <= addr < limit):
            continue
        if addr in done:
            continue
        out.append({"name": name, "addr": addr, "size": size, "mode": fmode})
        if count and len(out) >= count:
            break
    return out


# ----------------------------------------------------------------------------- helpers
def squash(op_str):
    return op_str.replace(" ", "")


def imm(op_str):
    m = re.search(r"#(-?0x[0-9a-fA-F]+|-?\d+)", op_str)
    return int(m.group(1), 0) if m else None


def cfunc(name, ret, params, body):
    return f"{ret} {name}({params}) {{ {body} }}\n"


def pretty(c_source):
    """Reformat a one-line cfunc() into the repo's brace-on-own-line style."""
    m = re.match(r"^(.*?) \{ (.*?) \}\s*$", c_source.strip())
    if not m:
        return c_source if c_source.endswith("\n") else c_source + "\n"
    sig, body = m.group(1), m.group(2).strip()
    inner = f"    {body}\n" if body else ""
    return f"{sig}\n{{\n{inner}}}\n"


# Load/store width tables: mnemonic -> (C pointer type, element size in bytes)
LOADS = {
    "ldr": ("int", 4), "ldrb": ("unsigned char", 1), "ldrsb": ("signed char", 1),
    "ldrh": ("unsigned short", 2), "ldrsh": ("short", 2),
}
STORES = {
    "str": ("int", 4), "strb": ("char", 1), "strh": ("short", 2),
}
ARITH = {"add": "+", "sub": "-", "orr": "|", "and": "&", "eor": "^", "mul": "*"}

MEM_RE = re.compile(r"^r0,\[r0(?:,#(-?0x[0-9a-fA-F]+|-?\d+))?\]$")   # ldr  dst r0, base r0
ST_RE = re.compile(r"^r1,\[r0(?:,#(-?0x[0-9a-fA-F]+|-?\d+))?\]$")    # str  src r1, base r0


# ----------------------------------------------------------------------------- rules
# Each rule: (name, insns, raw_bytes) -> (c_source, rule_label) or None.
def rule_empty(name, ins, b):
    if len(ins) == 1 and ins[0].mnemonic == "bx" and squash(ins[0].op_str) == "lr":
        return cfunc(name, "void", "void", ""), "empty/identity"
    return None


def rule_ret_const(name, ins, b):
    if len(ins) == 2 and ins[1].mnemonic == "bx":
        i = ins[0]
        s = squash(i.op_str)
        if i.mnemonic == "mov" and s.startswith("r0,#"):
            n = imm(s)
            if n is not None:
                return cfunc(name, "int", "void", f"return {n};"), "ret_const"
        if i.mnemonic == "mvn" and s.startswith("r0,#"):
            n = imm(s)
            if n is not None:
                return cfunc(name, "int", "void", f"return {~n};"), "ret_const_mvn"
    return None


def rule_ret_arg(name, ins, b):
    if len(ins) == 2 and ins[1].mnemonic == "bx" and ins[0].mnemonic == "mov":
        m = re.fullmatch(r"r0,r([0-3])", squash(ins[0].op_str))
        if m:
            n = int(m.group(1))
            params = ", ".join(f"int a{k}" for k in range(n + 1))
            return cfunc(name, "int", params, f"return a{n};"), "ret_arg"
    return None


def rule_load(name, ins, b):
    if len(ins) == 2 and ins[1].mnemonic == "bx" and ins[0].mnemonic in LOADS:
        m = MEM_RE.match(squash(ins[0].op_str))
        if m:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                idx = off // esize
                return cfunc(name, "int", f"{ptype} *p", f"return p[{idx}];"), "load_field"
    return None


def rule_store(name, ins, b):
    if len(ins) == 2 and ins[1].mnemonic == "bx" and ins[0].mnemonic in STORES:
        m = ST_RE.match(squash(ins[0].op_str))
        if m:
            ptype, esize = STORES[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                idx = off // esize
                return cfunc(name, "void", f"{ptype} *p, int v", f"p[{idx}] = v;"), "store_field"
    return None


def rule_arith(name, ins, b):
    if len(ins) == 2 and ins[1].mnemonic == "bx" and ins[0].mnemonic in ARITH:
        if re.fullmatch(r"r0,r0,r1", squash(ins[0].op_str)):
            op = ARITH[ins[0].mnemonic]
            return cfunc(name, "int", "int a, int b", f"return a {op} b;"), "arith2"
    return None


GG_RE = re.compile(r"^r0,\[r0(?:,#(0x[0-9a-fA-F]+|\d+))?\]$")   # <load> r0, [r0, #off]


def rule_global_getter(name, ins, b):
    # ldr r0,[pc,#x] ; <load> r0,[r0,#off] ; bx lr ; .word G  -> return a global field.
    # The .word is the global's absolute address: a relocation the oracle wildcards.
    if (len(ins) >= 3 and ins[0].mnemonic == "ldr"
            and squash(ins[0].op_str).startswith("r0,[pc")
            and ins[1].mnemonic in LOADS
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr"):
        m = GG_RE.match(squash(ins[1].op_str))
        if m:
            ptype, esize = LOADS[ins[1].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                src = (f"extern {ptype} G[];\n"
                       f"int {name}(void) {{ return G[{off // esize}]; }}\n")
                return src, "global_getter"
    return None


IMM = r"#(0x[0-9a-fA-F]+|\d+)"


def rule_load_mask(name, ins, b):
    # <load> r0,[r0(,#off)] ; and r0,r0,#imm ; bx lr   -> return field & imm
    if (len(ins) == 3 and ins[0].mnemonic in LOADS and ins[1].mnemonic == "and"
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr"):
        m = MEM_RE.match(squash(ins[0].op_str))
        a = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        if m and a:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "int", f"{ptype} *p",
                             f"return p[{off // esize}] & {int(a.group(1), 0)};"), "load_mask"
    return None


def rule_store_const(name, ins, b):
    # mov rX,#imm ; <store> rX,[r0(,#off)] ; bx lr   -> p[idx] = imm
    if (len(ins) == 3 and ins[0].mnemonic == "mov" and ins[1].mnemonic in STORES
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr"):
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[0].op_str))
        if mv:
            st = re.fullmatch(mv.group(1) + r",\[r0(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                ptype, esize = STORES[ins[1].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return cfunc(name, "void", f"{ptype} *p",
                                 f"p[{off // esize}] = {int(mv.group(2), 0)};"), "store_const"
    return None


def rule_global_setter(name, ins, b):
    # ldr rB,[pc..] ; <store> r0,[rB(,#off)] ; bx lr ; .word G   -> GLOBAL.field = arg
    if (len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in STORES
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr"):
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        if ld:
            st = re.fullmatch(r"r0,\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                ptype, esize = STORES[ins[1].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return (f"extern {ptype} G[];\n"
                            f"void {name}(int v) {{ G[{off // esize}] = v; }}\n"), "global_setter"
    return None


def rule_store_global_addr(name, ins, b):
    # ldr rX,[pc..] ; str rX,[r0(,#off)] ; bx lr ; .word G   -> p[idx] = &global (vtable install)
    if (len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "str"
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr"):
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        if ld:
            st = re.fullmatch(ld.group(1) + r",\[r0(?:," + IMM + r")?\]", squash(ins[1].op_str))
            if st:
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % 4 == 0:
                    return (f"extern int G[];\n"
                            f"void {name}(int *p) {{ p[{off // 4}] = (int)G; }}\n"), "store_global_addr"
    return None


def rule_field_bitop(name, ins, b):
    # add rB,r0,#off ; ldr rV,[rB] ; orr|bic rV,rV,#imm ; str rV,[rB] ; bx lr
    if (len(ins) == 5 and ins[0].mnemonic == "add" and ins[1].mnemonic == "ldr"
            and ins[2].mnemonic in ("orr", "bic") and ins[3].mnemonic == "str"
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr"):
        a = re.fullmatch(r"(r\d+),r0," + IMM, squash(ins[0].op_str))
        if a:
            rB = a.group(1)
            ld = re.fullmatch(r"(r\d+),\[" + rB + r"\]", squash(ins[1].op_str))
            op = re.fullmatch(r"(r\d+),(r\d+)," + IMM, squash(ins[2].op_str))
            stm = re.fullmatch(r"(r\d+),\[" + rB + r"\]", squash(ins[3].op_str))
            off = int(a.group(2), 0)
            if ld and op and stm and off % 4 == 0:
                imm = int(op.group(3), 0)
                idx = off // 4
                body = f"p[{idx}] |= {imm};" if ins[2].mnemonic == "orr" else f"p[{idx}] &= ~{imm};"
                return cfunc(name, "void", "int *p", body), "field_bitop"
    return None


def rule_cmp_eq(name, ins, b):
    # <load> r0,[r0(,#off)] ; cmp r0,#k ; moveq r0,#a ; movne r0,#bv ; bx lr  -> return p[i] ==/!= k
    if len(ins) == 5 and ins[0].mnemonic in LOADS and ins[1].mnemonic == "cmp" \
            and ins[2].mnemonic == "moveq" and ins[3].mnemonic == "movne" \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        m = MEM_RE.match(squash(ins[0].op_str))
        c = re.fullmatch(r"r0," + IMM, squash(ins[1].op_str))
        eq = re.fullmatch(r"r0," + IMM, squash(ins[2].op_str))
        ne = re.fullmatch(r"r0," + IMM, squash(ins[3].op_str))
        if m and c and eq and ne:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            eqv, nev = int(eq.group(1), 0), int(ne.group(1), 0)
            if off % esize == 0 and {eqv, nev} == {0, 1}:
                op = "==" if eqv == 1 else "!="
                return cfunc(name, "int", f"{ptype} *p",
                             f"return p[{off // esize}] {op} {int(c.group(1), 0)};"), "cmp_eq"
    return None


def rule_struct_copy(name, ins, b):
    # K pairs of ldr rT,[BASE,#o] ; str rT,[OTHER,#o] (bases r0/r1, consistent) ; bx lr
    if len(ins) < 3 or len(ins) % 2 == 0:
        return None
    if not (ins[-1].mnemonic == "bx" and squash(ins[-1].op_str) == "lr"):
        return None
    lbase = sbase = None
    pairs = []
    for k in range(0, len(ins) - 1, 2):
        ld, st = ins[k], ins[k + 1]
        if ld.mnemonic != "ldr" or st.mnemonic != "str":
            return None
        lm = re.fullmatch(r"(r\d+),\[(r[01])(?:," + IMM + r")?\]", squash(ld.op_str))
        sm = re.fullmatch(r"(r\d+),\[(r[01])(?:," + IMM + r")?\]", squash(st.op_str))
        if not (lm and sm and lm.group(1) == sm.group(1)):
            return None
        if lbase is None:
            lbase, sbase = lm.group(2), sm.group(2)
        if (lm.group(2), sm.group(2)) != (lbase, sbase) or lbase == sbase:
            return None
        soff = int(lm.group(3), 0) if lm.group(3) else 0
        doff = int(sm.group(3), 0) if sm.group(3) else 0
        if soff % 4 or doff % 4:
            return None
        pairs.append((doff // 4, soff // 4))
    nm = {"r0": "a", "r1": "b"}                       # r0 = first param, r1 = second
    src, dst = nm[lbase], nm[sbase]
    body = " ".join(f"{dst}[{d}] = {src}[{s}];" for d, s in pairs)
    return cfunc(name, "void", "int *a, int *b", body), "struct_copy"


def rule_add_imm(name, ins, b):
    # add/sub r0,r0,#imm ; bx lr   -> return arg +/- imm  (e.g. &this->field)
    if len(ins) == 2 and ins[0].mnemonic in ("add", "sub") \
            and ins[1].mnemonic == "bx" and squash(ins[1].op_str) == "lr":
        m = re.fullmatch(r"r0,r0," + IMM, squash(ins[0].op_str))
        if m:
            sign = "+" if ins[0].mnemonic == "add" else "-"
            return cfunc(name, "int", "int p", f"return p {sign} {int(m.group(1), 0)};"), "add_imm"
    return None


# unsigned load types -- needed so `>>` emits a logical shift (lsr), not arithmetic (asr)
UWORD = {"ldr": ("unsigned int", 4), "ldrb": ("unsigned char", 1), "ldrh": ("unsigned short", 2)}


def rule_bitfield(name, ins, b):
    # <load> r0,[r0(,#off)] ; lsr r0,r0,#sh ; and r0,r0,#mask ; bx lr
    if len(ins) == 4 and ins[0].mnemonic in UWORD and ins[1].mnemonic == "lsr" \
            and ins[2].mnemonic == "and" and ins[3].mnemonic == "bx" \
            and squash(ins[3].op_str) == "lr":
        m = MEM_RE.match(squash(ins[0].op_str))
        sh = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        mk = re.fullmatch(r"r0,r0," + IMM, squash(ins[2].op_str))
        if m and sh and mk:
            ptype, esize = UWORD[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            if off % esize == 0:
                return cfunc(name, "int", f"{ptype} *p",
                             f"return (p[{off // esize}] >> {int(sh.group(1), 0)}) & "
                             f"{int(mk.group(1), 0)};"), "bitfield"
    return None


def rule_global_store_const(name, ins, b):
    # ldr rB,[pc] ; mov rV,#imm ; <store> rV,[rB(,#off)] ; bx lr ; .word G
    if len(ins) >= 4 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "mov" \
            and ins[2].mnemonic in STORES and ins[3].mnemonic == "bx" \
            and squash(ins[3].op_str) == "lr":
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+)," + IMM, squash(ins[1].op_str))
        if ld and mv:
            st = re.fullmatch(mv.group(1) + r",\[" + ld.group(1) + r"(?:," + IMM + r")?\]",
                              squash(ins[2].op_str))
            if st:
                ptype, esize = STORES[ins[2].mnemonic]
                off = int(st.group(1), 0) if st.group(1) else 0
                if off % esize == 0:
                    return (f"extern {ptype} G[];\n"
                            f"void {name}(void) {{ G[{off // esize}] = "
                            f"{int(mv.group(2), 0)}; }}\n"), "global_store_const"
    return None


def rule_global_index(name, ins, b):
    # ldr rB,[pc] ; <load> r0,[rB,r0(,lsl #k)] ; bx lr ; .word G   -> return G[i]
    if len(ins) >= 3 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in LOADS \
            and ins[2].mnemonic == "bx" and squash(ins[2].op_str) == "lr":
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        if ld:
            idx = re.fullmatch(r"r0,\[" + ld.group(1) + r",r0(?:,lsl" + IMM + r")?\]",
                               squash(ins[1].op_str))
            if idx:
                ptype, _ = LOADS[ins[1].mnemonic]
                return (f"extern {ptype} G[];\n"
                        f"int {name}(int i) {{ return G[i]; }}\n"), "global_index"
    return None


def rule_two_global_setters(name, ins, b):
    # ldr rB,[pc] ; ldr rC,[pc] ; <store> r0,[rB] ; <store> r1,[rC] ; bx lr ; .word A ; .word B
    if len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "ldr" \
            and ins[2].mnemonic in STORES and ins[3].mnemonic == ins[2].mnemonic \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        b0 = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        b1 = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[1].op_str))
        if b0 and b1:
            s0 = re.fullmatch(r"r0,\[" + b0.group(1) + r"\]", squash(ins[2].op_str))
            s1 = re.fullmatch(r"r1,\[" + b1.group(1) + r"\]", squash(ins[3].op_str))
            if s0 and s1:
                ptype, _ = STORES[ins[2].mnemonic]
                return (f"extern {ptype} A[]; extern {ptype} B[];\n"
                        f"void {name}(int a, int b) {{ A[0] = a; B[0] = b; }}\n"), "two_global_setters"
    return None


def rule_global_field_bitop(name, ins, b):
    # ldr rB,[pc] ; <load> rV,[rB,#off] ; orr|bic rV,rV,#imm ; <store> rV,[rB,#off] ; bx lr
    if len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic in LOADS \
            and ins[2].mnemonic in ("orr", "bic") and ins[3].mnemonic in STORES \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        ld0 = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        if ld0:
            rB = ld0.group(1)
            lm = re.fullmatch(r"(r\d+),\[" + rB + r"(?:," + IMM + r")?\]", squash(ins[1].op_str))
            op = re.fullmatch(r"(r\d+),(r\d+)," + IMM, squash(ins[2].op_str))
            sm = re.fullmatch(r"(r\d+),\[" + rB + r"(?:," + IMM + r")?\]", squash(ins[3].op_str))
            if lm and op and sm:
                ltype, lesz = LOADS[ins[1].mnemonic]
                _, sesz = STORES[ins[3].mnemonic]
                off = int(lm.group(2), 0) if lm.group(2) else 0
                soff = int(sm.group(2), 0) if sm.group(2) else 0
                if lesz == sesz and off == soff and off % lesz == 0:
                    imm = int(op.group(3), 0)
                    idx = off // lesz
                    body = f"G[{idx}] |= {imm};" if ins[2].mnemonic == "orr" else f"G[{idx}] &= ~{imm};"
                    return (f"extern {ltype} G[];\nvoid {name}(void) {{ {body} }}\n"), "global_field_bitop"
    return None


def rule_bit_test(name, ins, b):
    # <load> r0,[r0(,#off)] ; ands r0,r0,#mask ; moveq r0,#a ; movne r0,#bv ; bx lr
    if len(ins) == 5 and ins[0].mnemonic in LOADS and ins[1].mnemonic == "ands" \
            and ins[2].mnemonic == "moveq" and ins[3].mnemonic == "movne" \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        m = MEM_RE.match(squash(ins[0].op_str))
        a = re.fullmatch(r"r0,r0," + IMM, squash(ins[1].op_str))
        eq = re.fullmatch(r"r0," + IMM, squash(ins[2].op_str))
        ne = re.fullmatch(r"r0," + IMM, squash(ins[3].op_str))
        if m and a and eq and ne:
            ptype, esize = LOADS[ins[0].mnemonic]
            off = int(m.group(1), 0) if m.group(1) else 0
            eqv, nev = int(eq.group(1), 0), int(ne.group(1), 0)
            if off % esize == 0 and {eqv, nev} == {0, 1}:
                op = "==" if eqv == 1 else "!="
                return cfunc(name, "int", f"{ptype} *p",
                             f"return (p[{off // esize}] & {int(a.group(1), 0)}) {op} 0;"), "bit_test"
    return None


def rule_two_indexed_store(name, ins, b):
    # ldr rB,[pc] ; ldr rC,[pc] ; str r1,[rB,r0,lsl #2] ; strb r2,[rC,r0] ; bx lr ; .word A ; .word B
    if len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "ldr" \
            and ins[2].mnemonic == "str" and ins[3].mnemonic == "strb" \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        b0 = re.fullmatch(r"(r\d+|ip|sb|sl|fp),\[pc.*\]", squash(ins[0].op_str))
        b1 = re.fullmatch(r"(r\d+|ip|sb|sl|fp),\[pc.*\]", squash(ins[1].op_str))
        if b0 and b1 \
                and re.fullmatch(r"r1,\[" + b0.group(1) + r",r0,lsl#2\]", squash(ins[2].op_str)) \
                and re.fullmatch(r"r2,\[" + b1.group(1) + r",r0\]", squash(ins[3].op_str)):
            return ("extern int A[]; extern unsigned char B[];\n"
                    f"void {name}(int i, int v1, int v2) {{ A[i] = v1; B[i] = v2; }}\n"), "two_indexed_store"
    return None


def rule_setbit_byidx(name, ins, b):
    # ldr rB,[pc] ; mov rV,#1 ; ldr rW,[rB,#off] ; orr r0,rW,rV,lsl r0 ; str r0,[rB,#off] ; bx lr
    if len(ins) >= 6 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "mov" \
            and ins[2].mnemonic == "ldr" and ins[3].mnemonic == "orr" \
            and ins[4].mnemonic == "str" and ins[5].mnemonic == "bx" \
            and squash(ins[5].op_str) == "lr":
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+),#1", squash(ins[1].op_str))
        if ld and mv:
            lw = re.fullmatch(r"(r\d+),\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[2].op_str))
            orr = re.fullmatch(r"r0,(r\d+)," + mv.group(1) + r",lslr0", squash(ins[3].op_str))
            st = re.fullmatch(r"r0,\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[4].op_str))
            if lw and orr and st:
                off = int(lw.group(2), 0) if lw.group(2) else 0
                if off % 4 == 0:
                    return ("extern int G[];\n"
                            f"void {name}(int n) {{ G[{off // 4}] |= 1 << n; }}\n"), "setbit_byidx"
    return None


def rule_testbit_byidx(name, ins, b):
    # ldr rB,[pc] ; mov rV,#1 ; ldr rW,[rB,#off] ; and r0,rW,rV,lsl r0 ; bx lr
    if len(ins) >= 5 and ins[0].mnemonic == "ldr" and ins[1].mnemonic == "mov" \
            and ins[2].mnemonic == "ldr" and ins[3].mnemonic == "and" \
            and ins[4].mnemonic == "bx" and squash(ins[4].op_str) == "lr":
        ld = re.fullmatch(r"(r\d+),\[pc.*\]", squash(ins[0].op_str))
        mv = re.fullmatch(r"(r\d+),#1", squash(ins[1].op_str))
        if ld and mv:
            lw = re.fullmatch(r"(r\d+),\[" + ld.group(1) + r"(?:," + IMM + r")?\]", squash(ins[2].op_str))
            a = re.fullmatch(r"r0,(r\d+)," + mv.group(1) + r",lslr0", squash(ins[3].op_str))
            if lw and a:
                off = int(lw.group(2), 0) if lw.group(2) else 0
                if off % 4 == 0:
                    return ("extern int G[];\n"
                            f"int {name}(int n) {{ return G[{off // 4}] & (1 << n); }}\n"), "testbit_byidx"
    return None


def rule_pool_const(name, ins, b):
    # ldr r0, [pc, #..] ; bx lr ; .word N   (size 12)
    # Must load into r0 (the return reg) and RETURN (bx lr) -- not a thunk (bx ip).
    if len(b) >= 12 and ins and ins[0].mnemonic == "ldr":
        s0 = squash(ins[0].op_str)
        if s0.startswith("r0,[pc") and any(
                i.mnemonic == "bx" and squash(i.op_str) == "lr" for i in ins[:3]):
            word = int.from_bytes(b[8:12], "little")
            signed = word - (1 << 32) if word >= (1 << 31) else word
            return cfunc(name, "int", "void", f"return {signed};"), "pool_const"
    return None


def is_thunk(ins):
    """Tail-call / linker veneer: a computed jump `bx <reg>` to anything but lr.
    These are link-time artifacts -- not reproducible from a single C function."""
    return any(i.mnemonic == "bx" and squash(i.op_str) != "lr" for i in ins)


# ----------------------------------------------------------------------------- reloc-aware rules
# These need the function's address + the reloc/symbol tables, so they take a
# wider signature than the leaf rules. They resolve `bl` targets to real names.
def callee_name(addr, ins, relocs, syms):
    """Resolved name of the first bl/blx callee in the function, or None."""
    for i in ins:
        if i.mnemonic in ("bl", "blx"):
            entry = relocs.get(addr + i.address)
            if entry:
                return R.name_of(entry[1], syms)
    return None


def rule_wrapper(name, ins, b, addr, relocs, syms):
    # push {r4,lr} ; mov r4,r0 ; bl X ; mov r0,r4 ; pop {r4,lr} ; bx lr
    #   -> call X for its side effect, return the original arg
    m = [i.mnemonic for i in ins]
    if m[:6] == ["push", "mov", "bl", "mov", "pop", "bx"] \
            and squash(ins[5].op_str) == "lr" \
            and squash(ins[1].op_str) == "r4,r0" and squash(ins[3].op_str) == "r0,r4":
        callee = callee_name(addr, ins, relocs, syms)
        if callee and callee != name:
            return (f"extern int {callee}();\n"
                    f"int {name}(int x) {{ {callee}(x); return x; }}\n"), "wrapper"
    return None


def rule_ctor_vtable(name, ins, b, addr, relocs, syms):
    # push {r4,lr} ; ldr r1,[pc] ; mov r4,r0 ; str r1,[r4] ; bl X ; mov r0,r4 ; pop ; bx lr ; .word VT
    #   -> install vtable into *this, call X(this), return this
    m = [i.mnemonic for i in ins]
    if m[:8] == ["push", "ldr", "mov", "str", "bl", "mov", "pop", "bx"] \
            and squash(ins[7].op_str) == "lr" \
            and re.fullmatch(r"r1,\[pc.*\]", squash(ins[1].op_str)) \
            and squash(ins[2].op_str) == "r4,r0" \
            and squash(ins[3].op_str) == "r1,[r4]" \
            and squash(ins[5].op_str) == "r0,r4":
        callee = callee_name(addr, ins, relocs, syms)
        if callee and callee != name:
            return (f"extern int VT[]; extern int {callee}();\n"
                    f"int {name}(int *x) {{ x[0] = (int)VT; {callee}(x); return (int)x; }}\n"), "ctor_vtable"
    return None


def rule_chain_dtor(name, ins, b, addr, relocs, syms):
    # push {r4,lr} ; mov r4,r0 ; [ (add r0,r4,#off)? ; bl X ]+ ; mov r0,r4 ; pop {r4,lr} ; bx lr
    #   -> destructor-style chain: call each helper on this(+off), return this
    if not (ins[0].mnemonic == "push" and ins[1].mnemonic == "mov"
            and squash(ins[1].op_str) == "r4,r0"):
        return None
    if not (len(ins) >= 6 and ins[-1].mnemonic == "bx" and squash(ins[-1].op_str) == "lr"
            and ins[-2].mnemonic == "pop" and ins[-3].mnemonic == "mov"
            and squash(ins[-3].op_str) == "r0,r4"):
        return None
    body = ins[2:-3]
    calls, i = [], 0
    while i < len(body):
        if body[i].mnemonic == "bl":                       # r0 already = this
            off, bi, i = 0, body[i], i + 1
        elif body[i].mnemonic == "add" and i + 1 < len(body) and body[i + 1].mnemonic == "bl":
            mm = re.fullmatch(r"r0,r4," + IMM, squash(body[i].op_str))
            if not mm:
                return None
            off, bi, i = int(mm.group(1), 0), body[i + 1], i + 2
        elif body[i].mnemonic == "mov" and squash(body[i].op_str) == "r0,r4" \
                and i + 1 < len(body) and body[i + 1].mnemonic == "bl":
            off, bi, i = 0, body[i + 1], i + 2
        else:
            return None
        e = relocs.get(addr + bi.address)
        if not e:
            return None
        calls.append((off, R.name_of(e[1], syms)))
    if not calls:
        return None
    decls = "".join(f"extern int {c}();\n" for c in dict.fromkeys(c for _, c in calls))
    lines = "".join(f"    {c}(t{f' + {off:#x}' if off else ''});\n" for off, c in calls)
    if name in (c for _, c in calls):
        return None
    return f"{decls}\nint {name}(char *t)\n{{\n{lines}    return (int)t;\n}}\n", "chain_dtor"


def rule_guard_call(name, ins, b, addr, relocs, syms):
    # push{r4,lr}; mov r4,r0; bl C1; cmp r0,#0; popeq; bxeq; mov r0,r4; bl C2; pop; bx lr
    #   -> r = C1(this); if (r == 0) return r; return C2(this);
    if [i.mnemonic for i in ins] != ["push", "mov", "bl", "cmp", "popeq", "bxeq",
                                     "mov", "bl", "pop", "bx"]:
        return None
    if squash(ins[1].op_str) != "r4,r0" or squash(ins[3].op_str) != "r0,#0" \
            or squash(ins[6].op_str) != "r0,r4" or squash(ins[9].op_str) != "lr":
        return None
    e1, e2 = relocs.get(addr + ins[2].address), relocs.get(addr + ins[7].address)
    if not (e1 and e2):
        return None
    c1, c2 = R.name_of(e1[1], syms), R.name_of(e2[1], syms)
    if name in (c1, c2):
        return None
    decls = f"extern int {c1}();\n" + (f"extern int {c2}();\n" if c2 != c1 else "")
    return (f"{decls}\nint {name}(char *t)\n{{\n    int r = {c1}(t);\n"
            f"    if (r == 0) return r;\n    return {c2}(t);\n}}\n"), "guard_call"


RELOC_RULES = [rule_wrapper, rule_ctor_vtable, rule_chain_dtor, rule_guard_call]


RULES = [rule_empty, rule_ret_const, rule_ret_arg, rule_load, rule_load_mask,
         rule_bitfield, rule_store, rule_store_const, rule_arith, rule_add_imm,
         rule_global_getter, rule_global_setter, rule_global_index,
         rule_global_store_const, rule_store_global_addr, rule_field_bitop,
         rule_global_field_bitop, rule_two_global_setters, rule_two_indexed_store,
         rule_setbit_byidx, rule_testbit_byidx, rule_bit_test, rule_cmp_eq,
         rule_struct_copy, rule_pool_const]


# ----------------------------------------------------------------------------- oracle
def oracle_ok(c_source, name, target):
    """Compile candidate C and relocation-aware byte-diff against the ROM."""
    with tempfile.TemporaryDirectory() as td:
        cfile = pathlib.Path(td) / "cand.c"
        cfile.write_text(c_source)
        obj = M.compile_c(cfile, M.CANONICAL, M.DEFAULT_FLAGS)
    if obj is None:
        return False
    code, relocs = M.extract_func(obj, name)
    if code is None:
        return False
    ok, _ = M.compare(target, code, relocs, verbose=False)
    return ok


# ----------------------------------------------------------------------------- main
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0x4)
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x40)
    ap.add_argument("--count", type=int, default=0, help="0 = all unmatched in range")
    ap.add_argument("--mode", default="arm", choices=["arm", "thumb", "any"])
    ap.add_argument("--apply", action="store_true", help="append wins to matched.jsonl")
    ap.add_argument("--verbose", action="store_true", help="print each win's C")
    args = ap.parse_args()

    targets = enumerate_targets(args.min, args.max, args.mode, args.count)
    relocs, syms = R.load_relocs(), R.load_syms()
    print(f"scanning {len(targets)} unmatched {args.mode} functions "
          f"(size 0x{args.min:x}-0x{args.max:x})\n")

    stats = {}
    wins = []
    proposed = 0
    for t in targets:
        tgt = M.target_bytes(t["addr"], t["size"])
        ins = list(md.disasm(tgt, 0))
        if is_thunk(ins):
            stats["(thunk skipped)"] = stats.get("(thunk skipped)", 0) + 1
            continue
        cand = None
        for rule in RULES:
            cand = rule(t["name"], ins, tgt)
            if cand:
                break
        if not cand:
            for rule in RELOC_RULES:
                cand = rule(t["name"], ins, tgt, t["addr"], relocs, syms)
                if cand:
                    break
        if not cand:
            stats["(no template)"] = stats.get("(no template)", 0) + 1
            continue
        proposed += 1
        c_source, label = cand
        if oracle_ok(c_source, t["name"], tgt):
            stats[label] = stats.get(label, 0) + 1
            wins.append((t, label, c_source))
            if args.verbose:
                print(f"  MATCH {t['name']} @ 0x{t['addr']:08x}  [{label}]  {c_source.strip()}")
        else:
            stats["(template miss)"] = stats.get("(template miss)", 0) + 1

    written_src = 0
    if args.apply and wins:
        src_dir = REPO / "src"
        with MATCHED.open("a") as f:
            for t, label, c_source in wins:
                f.write(json.dumps({
                    "addr": f"0x{t['addr']:08x}", "name": t["name"],
                    "size": t["size"], "module": "arm9",
                    "versions": [f"template:{label}"],
                }) + "\n")
                cpath = src_dir / f"{t['name']}.c"
                if not cpath.exists():
                    cpath.write_text(pretty(c_source))
                    written_src += 1

    print("=" * 52)
    matched = len(wins)
    print(f"templated candidates: {proposed}   |   MATCHED (zero tokens): {matched}")
    print("-" * 52)
    for label in sorted(stats, key=lambda k: -stats[k]):
        print(f"  {stats[label]:5}  {label}")
    if args.apply:
        print(f"\napplied: appended {matched} to matched.jsonl, wrote {written_src} src/*.c")
    elif matched:
        print("\n(dry-run: re-run with --apply to record these in matched.jsonl)")


if __name__ == "__main__":
    main()
