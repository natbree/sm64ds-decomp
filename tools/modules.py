"""Module registry: main ARM9 + every overlay.

Each module has its own binary, RAM base address, symbols, and relocs. Overlays
can share a base address (they occupy the same memory slot at different times),
so anything that records matches must key by (module, addr), never addr alone.
"""
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
EXTRACTED = REPO / "extracted"
CFG = REPO / "config" / "arm9"
OVL_YAML = EXTRACTED / "dsd" / "arm9_overlays" / "overlays.yaml"
ARM9_BASE = 0x02004000


def _overlay_bases():
    """{overlay_id: base_address} parsed from overlays.yaml."""
    out, cur = {}, None
    for line in OVL_YAML.read_text(errors="ignore").splitlines():
        m = re.match(r"\s*-\s*id:\s*(\d+)", line)
        if m:
            cur = int(m.group(1))
        m = re.match(r"\s*base_address:\s*(\d+)", line)
        if m and cur is not None:
            out[cur] = int(m.group(1))
            cur = None
    return out


def modules():
    """All modules as dicts: {name, syms, relocs, bin, base}."""
    mods = [{"name": "main", "syms": CFG / "symbols.txt", "relocs": CFG / "relocs.txt",
             "bin": EXTRACTED / "arm9_dec.bin", "base": ARM9_BASE}]
    for i, base in sorted(_overlay_bases().items()):
        d = CFG / "overlays" / f"ov{i:03d}"
        b = EXTRACTED / "overlays" / f"overlay_{i:04d}.bin"
        if d.is_dir() and b.is_file():
            mods.append({"name": f"ov{i:03d}", "syms": d / "symbols.txt",
                         "relocs": d / "relocs.txt", "bin": b, "base": base})
    return mods


def read_bytes(mod, addr, size):
    """Bytes of [addr, addr+size) from a module's binary."""
    off = addr - mod["base"]
    return mod["bin"].read_bytes()[off:off + size]
