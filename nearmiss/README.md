# Near-miss database

`db.jsonl` is the persistent store of close-but-not-matched function attempts -- compiling
C from the fan-out (and hand-cracking) that did not byte-match, kept forever and ranked by
how few instructions diverge from the ROM. These are the most valuable byproduct of the
matching effort: logically correct, already compiling, often 1-4 instructions from done.

Why keep them: re-deriving a near-match costs LLM tokens; finishing one is cheap (a small
fix, the permuter, or a stronger future model). This pre-positions the hard residue at ~95%
so the final push is fast and cheap instead of starting from scratch.

One record per (module, addr), keeping the CLOSEST candidate:
  {module, addr, name, size, target_hex, lang, divergences, c_source, source}

Managed by `tools/nearmiss_db.py` (ingest / stats / list / export-close / bank-matches).
Run `python tools/permuter/crunch.py` to grind the closest ones through the permuter locally
(free), banking any that reach a match.
