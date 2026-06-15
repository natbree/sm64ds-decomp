"""Resolve relocations and symbols for the ARM9 module.

For call-having functions, the literal `bl` target is a relocation slot the oracle
wildcards -- so a leaf-style template can't trust it. But config/arm9/relocs.txt
records the EXACT target of every call/load, and symbols.txt names it. That lets
us emit C that calls the *right* function by name: byte-matching AND semantically
correct, with no LLM. This module is the shared resolver.
"""
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
RELOCS = REPO / "config" / "arm9" / "relocs.txt"
SYMS = REPO / "config" / "arm9" / "symbols.txt"

_REL_RE = re.compile(r"from:0x([0-9a-fA-F]+) kind:(\S+) to:0x([0-9a-fA-F]+) module:(\S+)")
_SYM_RE = re.compile(r"^(\S+)\s+kind:\S+\s+addr:0x([0-9a-fA-F]+)")


def load_relocs_file(path):
    """{from_addr: (kind, to_addr, module)} for one relocs.txt."""
    d = {}
    for line in pathlib.Path(path).read_text(errors="ignore").splitlines():
        m = _REL_RE.match(line)
        if m:
            d[int(m.group(1), 16)] = (m.group(2), int(m.group(3), 16), m.group(4))
    return d


def load_syms_file(path):
    """{addr: name} for one symbols.txt."""
    d = {}
    for line in pathlib.Path(path).read_text(errors="ignore").splitlines():
        m = _SYM_RE.match(line)
        if m:
            d[int(m.group(2), 16)] = m.group(1)
    return d


def load_relocs():
    return load_relocs_file(RELOCS)


def load_syms():
    return load_syms_file(SYMS)


def load_all_syms():
    """Merged addr->name across every module (best-effort cross-module naming)."""
    import modules as MOD
    d = {}
    for mod in MOD.modules():
        d.update(load_syms_file(mod["syms"]))
    return d


def name_of(addr, syms):
    """Symbol name for an address, or the func_<addr> convention if unnamed."""
    return syms.get(addr, f"func_{addr:08x}")
