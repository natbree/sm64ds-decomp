//cpp
struct C; typedef void (C::*PMF)();
struct Entry { PMF pmf[2]; };
extern Entry TABLE[];
struct C { char pad[0x6c8]; int idx; };
extern "C" void func_ov063_0211ddf4(C *c) { int j = c->idx; (c->*TABLE[j].pmf[1])(); }
