# Getting mwccarm + NITRO-SDK (the one human-gated step)

`mwccarm` (Metrowerks CodeWarrior ARM) is proprietary and not redistributable, so it
isn't downloadable directly. It's free but lives in the decomp community's Discord.

## Where
The **DS Decompilation Discord** (a.k.a. the pret/DS-decomp server). Invite is linked
from the dsd toolkit's community section: https://github.com/AetiasHax/ds-decomp
(look for the #dsd channel / pinned messages). The pret Discord servers
(pokediamond/pokeheartgold) have the same pinned files.

## What to grab (from the pinned messages)
1. **`mwccarm.zip`**, the whole set of CodeWarrior ARM compiler versions. It contains
   subfolders like `1.2/`, `2.0/` with service-pack subdirs (e.g. `sp1`, `sp2p2`),
   each holding `mwccarm.exe`, `mwldarm.exe`, `mwasmarm.exe`.
2. **`license.dat`**, the CodeWarrior license file (often bundled in the same zip or a
   sibling `.rar`).
3. A **NITRO-SDK** archive if pinned (e.g. `NitroSDK-*.7z`), needed later for SDK
   library headers/objects. Not required just to start matching game functions.

## Where to put it
- Extract `mwccarm.zip` to: `tools/mwccarm/` in this repo
  (so paths look like `tools/mwccarm/2.0/sp2p2/mwccarm.exe`).
  This folder is gitignored (proprietary, not redistributable).
- Set a Windows environment variable so the compiler finds its license:
  `LM_LICENSE_FILE` = full path to `license.dat`.
  (System Settings -> Environment Variables, or `setx LM_LICENSE_FILE "C:\...\license.dat"`)
- Windows bonus: `mwccarm.exe` is a native Windows binary, so no Wine needed.

## Which version do we actually need?
Unknown until we test (see recon notes). SM64DS is Nov 2004, so likely an early
CodeWarrior 1.x, but the dead matty45 repo guessed 2.0/sp2p2. Plan once the zip is
here: take one tiny already-identified leaf function, compile a candidate C version
with each mwccarm version, and byte-diff against the ROM in objdiff/decomp.me until one
matches. That match pins the version for the whole project.

## .gitignore
`tools/mwccarm/` and `license.dat` must never be committed.
