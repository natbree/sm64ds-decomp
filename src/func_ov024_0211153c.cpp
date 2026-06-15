//cpp
struct Base { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void m(int); };
struct Derived { char pad[0x320]; Base base; };
extern "C" int func_ov024_0211153c(Derived *d) { Base *b = &d->base; b->m(0); return 1; }
