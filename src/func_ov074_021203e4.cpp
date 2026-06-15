//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x5cc]; int idx; };
extern "C" void func_ov074_021203e4(C *c, int i) { c->idx = i; int j = c->idx; (c->*TABLE[j].pmf[0])(); }
