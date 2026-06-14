# sm64ds-decomp

A from-scratch effort to decompile **Super Mario 64 DS** into matching C.

## What "matching" means

The goal is source code that, when compiled with the *original toolchain*, produces
a binary **byte-for-byte identical** to the retail ROM. That's the bar real decomp
projects hold to (see the N64 `sm64` project). Anything less is "C that looks right";
matching is C that *is* right.

## Legal / scope

This repo contains **only original work**: our scripts, our hand-written C, our notes.
It contains **no ROM and no extracted Nintendo assets** — those are read locally from a
cartridge dump the user owns, and are git-ignored. Don't commit anything derived from
the ROM's data/assets.

## Layout

| Dir         | Holds                                                        |
|-------------|-------------------------------------------------------------|
| `tools/`    | our Python scripts (unpack ROM, disassemble, diff)          |
| `asm/`      | working disassembly listings (scratch; gitignored for now)  |
| `src/`      | hand-written matching C                                      |
| `include/`  | headers / type definitions we reconstruct                   |
| `extracted/`| ROM unpack output — **local only, gitignored**              |
| `notes/`    | findings: memory map, struct layouts, function index        |

## Status

- [x] Repo scaffolded
- [x] Toolchain: `ndspy`, `capstone`, `pyelftools` (Python) + `dsd` analysis
- [x] Milestone 1: unpack ROM, identify ARM9 + overlays, dump real functions
- [x] Milestone 2: original compiler pinned — **mwccarm `1.2/sp2p3`**
- [x] Milestone 3: byte-matching functions landing, end to end
- [ ] The long grind: ~11,390 functions to match (in progress)

## Building / toolchain setup

You supply your own cartridge dump; the repo holds only original work. To get set up
(Python deps, the proprietary `mwccarm` compiler from the DS-decomp Discord, the `dsd`
toolkit, and ROM unpacking), see **[CONTRIBUTING.md](CONTRIBUTING.md)** and
**[notes/setup-mwccarm.md](notes/setup-mwccarm.md)**.

## Workflow (the loop)

1. Unpack ROM -> ARM9 / ARM7 / overlays / filesystem (`tools/unpack.py`)
2. Disassemble a region to ARM (`tools/disasm.py`)
3. Hand-write C for one function
4. Compile with mwccarm and byte-diff against the ROM, relocation-aware (`tools/match.py`)
5. Iterate until identical, then move to the next function

## Contributing & contact

Help is welcome — every matched function counts. See **[CONTRIBUTING.md](CONTRIBUTING.md)**
for setup and the matching loop.

- **Discord: `beansntoast`** — DM me to claim work or ask questions.
- Or open an issue to claim a function/area so we don't double up.
