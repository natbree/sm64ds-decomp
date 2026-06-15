# Roadmap: from ROM to a native PC EXE

The North Star: a Windows `.exe` that runs Super Mario 64 DS natively on PC (no
emulator), built from source. This is achievable, it's exactly what happened to the
N64 game (`sm64-port`), but only as the FINAL stage of a long road. Here's the honest
sequence.

## Stage 1: Matching decompilation  [WE ARE HERE, ~11% of functions]
Rebuild the retail `.nds` byte-for-byte from hand-written C compiled with mwccarm.
This is the slow, rigorous part: ~11,390 functions. Matching guarantees the C is
*provably* the original logic. This stage alone is the multi-year effort.
- Output: source that `dsd rom build` turns back into the exact original ROM.

## Stage 2: Understood / portable C
A byte-matching function is correct but still written to mwccarm's quirks. For a port,
the engine + game logic must be in clean, portable C, and the DS hardware touchpoints
must be identified and isolated:
- 3D (GX / geometry engine), 2D engine, SPU audio, touch/input, NARC filesystem.
- These get walled behind an abstraction layer instead of poking DS registers.

## Stage 3: Port layer (the part that makes an EXE)
Replace the DS hardware layer with PC equivalents and compile for x86_64-windows:
- Graphics: reimplement the DS GX calls over OpenGL/your own renderer (this is the
  bulk of the porting work, the DS 3D pipeline is unusual).
- Audio: SDAT/SSEQ playback over SDL/your mixer.
- Input: keyboard/controller -> the game's input layer.
- Assets: loaded from files extracted from the user's own ROM at runtime.
- Output: `sm64ds.exe` linking against SDL2 + a GL renderer.

## Stage 4: Polish / "make everyone happy"
Widescreen, high-res, uncapped framerate, remappable controls, etc. (all the things
the N64 PC port added once the base port worked).

## Honest notes
- The N64 PC port appeared AFTER the matching decomp was essentially complete (2019).
  We are at the very start of Stage 1. Every matched function is a brick in this road;
  the EXE is the far end of it.
- "Make everyone happy" / sharing: the thing the community shares is the open-source
  CODE, which others build themselves against their own ROM. Distributing a compiled
  Nintendo-game EXE (or ROM/assets) reliably draws a Nintendo DMCA, that's what keeps
  happening to these ports. So the win condition is a great public repo people can
  build from their own cartridge, not a binary handed around. Same end result for an
  owner; very different legal exposure.
