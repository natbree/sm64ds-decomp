//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x1e4]; int idx; };
extern "C" void func_ov084_0212c960(C *c, int i) { c->idx = i; int j = c->idx; (c->*TABLE[j].pmf[0])(); }
