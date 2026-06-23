//cpp
extern "C" {
struct Vec3 { int x, y, z; };
extern unsigned int _ZNK6Player14GetBodyModelIDEjb(char* c, unsigned int a, int b);
extern void MulVec3Mat4x3(void* a, void* b, struct Vec3* out);
extern void Vec3_MulScalar(struct Vec3* out, struct Vec3* in, int s);
extern void Vec3_RotateYAndTranslate(struct Vec3* out, struct Vec3* in, int ang, char* arg);
extern void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
  unsigned int a, unsigned int b, int c, int d, int e, const void* f, void* g);

void func_ov002_020c37a4(char* self, char* arg){
  unsigned int id = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self+8) & 0xff, 0);
  int r6 = *(int*)(*(int*)(self + (id << 2) + 0xdc) + 0x14) + 0x180;
  unsigned int id2 = _ZNK6Player14GetBodyModelIDEjb(self, *(int*)(self+8) & 0xff, 0);
  struct Vec3 v;
  struct Vec3 s;
  MulVec3Mat4x3((void*)(r6 + 0x24), (void*)(*(int*)(self + (id2 << 2) + 0xdc) + 0x1c), &v);
  Vec3_MulScalar(&s, &v, 0x8000);
  v = s;
  Vec3_RotateYAndTranslate(&v, &v, *(short*)(self+0x8e), arg);
  *(void**)(self+0x628) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    *(unsigned int*)(self+0x628), 0x34, v.x, v.y, v.z, 0, 0);
  *(void**)(self+0x62c) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    *(unsigned int*)(self+0x62c), 0x35, v.x, v.y, v.z, 0, 0);

}
}
