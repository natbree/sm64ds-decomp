//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x3f0]; int idx; };
extern "C" void func_ov002_020ed684(C *c) { int j = c->idx; (c->*TABLE[j].pmf[1])(); }
