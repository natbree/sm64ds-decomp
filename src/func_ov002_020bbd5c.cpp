//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x354]; int idx; };
extern "C" void func_ov002_020bbd5c(C *c, int i) { c->idx = i; int j = c->idx; (c->*TABLE[j].pmf[0])(); }
