//cpp
struct Base { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int a(); virtual int b(); };
extern "C" int _ZN15FaderBrightness20IsBetweenStartAndEndEv(Base *c){
  if(c->a()==0 && c->b()==0) return 1;
  return 0;
}
