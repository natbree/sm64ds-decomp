//cpp
struct Base { virtual void v0(); virtual void v1(); virtual void m(void*,int,int); };
extern "C" void _ZN9ModelBase7SetFileEP8BMD_Fileii(Base *c, void *a, int b, int d){ c->m(a,b,d); }
