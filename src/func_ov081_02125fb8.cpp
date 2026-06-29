//cpp
typedef int Fix12;
struct Vector3 { int x, y, z; };

extern "C" char *_ZN5Actor10FindWithIDEj(unsigned int id);
extern "C" void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int a, Fix12 b, Fix12 c, Fix12 d);
extern "C" void _ZN9ActorBase18MarkForDestructionEv(void *self);
extern "C" void _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(void *self, const Vector3 &v, unsigned int a2, Fix12 a3, unsigned int a4, unsigned int a5, unsigned int a6);
extern "C" void func_02012694(int a, void *b);

struct Obj {
    char pad[0x5c];
    int f5c;
    int f60;
    int f64;
    char pad2[0x130 - 0x68];
    unsigned int f130;
    unsigned int f134;
};

extern "C" void func_ov081_02125fb8(Obj *self)
{
    if (self->f134 == 0) return;
    char *a = _ZN5Actor10FindWithIDEj(self->f134);
    if (a == 0) return;

    unsigned int flags = self->f130;
    if ((flags & 0x10) || (flags & 0x40000)) {
        _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x11c, self->f5c, self->f60, self->f64);
        _ZN9ActorBase18MarkForDestructionEv(self);
        return;
    }

    {
        int b = (*(unsigned short *)(a + 0xc) == 0xbf);
        if (b == 0) return;
    }
    if (*(unsigned char *)(a + 0x6fb) != 0) return;
    if (*(unsigned char *)(a + 0x6f9) == 1) {
        _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x11c, self->f5c, self->f60, self->f64);
        _ZN9ActorBase18MarkForDestructionEv(self);
        return;
    }
    {
        Vector3 v;
        v.x = self->f5c;
        v.y = self->f60;
        v.z = self->f64;
        _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(a, v, 1, 0xc000, 1, 0, 1);
        func_02012694(0x3c, (char *)self + 0x74);
        _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x11c, self->f5c, self->f60, self->f64);
        _ZN9ActorBase18MarkForDestructionEv(self);
    }
}
