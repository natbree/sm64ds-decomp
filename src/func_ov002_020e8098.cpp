//cpp
typedef long long s64;
struct Vec3 { int x, y, z; };

extern "C" int  _ZN9Animation8FinishedEv(void* anim);
extern "C" void func_ov002_020e8244(Vec3* out, char* self);
extern "C" void SubVec3(Vec3* a, Vec3* b, Vec3* c);
extern "C" void AddVec3(Vec3* a, Vec3* b, Vec3* c);
extern "C" void* _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
    unsigned int a, unsigned int b, int c, int d, int e, const void* f, void* g);

extern "C" void func_ov002_020e8098(char* self)
{
    Vec3 vc;
    Vec3 v;
    if (_ZN9Animation8FinishedEv(self + 0x35c)) return;
    func_ov002_020e8244(&v, self);
    vc.x = v.x;
    vc.y = v.y;
    vc.z = v.z;
    if (*(int*)(self + 0x440) != 0xd)
        vc.y = v.y + 0x32000;
    SubVec3(&vc, (Vec3*)(self + 0x5c), &vc);
    vc.x = (int)(((s64)vc.x * *(int*)(self + 0x80) + 0x800) >> 0xc);
    vc.y = (int)(((s64)vc.y * *(int*)(self + 0x84) + 0x800) >> 0xc);
    vc.z = (int)(((s64)vc.z * *(int*)(self + 0x88) + 0x800) >> 0xc);
    AddVec3(&vc, (Vec3*)(self + 0x5c), &vc);
    *(void**)(self + 0x4b4) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(unsigned int*)(self + 0x4b4), 0x115, vc.x, vc.y, vc.z, 0, 0);
    *(void**)(self + 0x4b8) = _ZN8Particle6System3NewEjj5Fix12IiES2_S2_PK11Vector3_16fPNS_8CallbackE(
        *(unsigned int*)(self + 0x4b8), 0x116, vc.x, vc.y, vc.z, 0, 0);
}
