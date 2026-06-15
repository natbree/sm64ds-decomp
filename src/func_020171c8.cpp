//cpp
struct Base { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void m(); };
extern "C" void func_020171c8(Base *c){ *(int*)((char*)c+8)=0x1000; c->m(); }
