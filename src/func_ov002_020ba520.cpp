//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x340]; int idx; };
extern "C" void func_ov002_020ba520(C *c) { int j = c->idx; (c->*TABLE[j].pmf[1])(); }
