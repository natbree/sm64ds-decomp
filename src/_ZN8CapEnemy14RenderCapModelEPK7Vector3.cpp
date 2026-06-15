//cpp
struct Vector3;
struct CapModel {
  virtual void f0(); virtual void f1(); virtual void f2();
  virtual void f3(); virtual void f4();
  virtual void render(const Vector3*);
};
extern "C" {
void _ZN8CapEnemy14RenderCapModelEPK7Vector3(char* c, const Vector3* v){
  if((unsigned char)c[0x113] >= 6) return;
  CapModel* o=(CapModel*)(c+0x114);
  o->render(v);
}
}
