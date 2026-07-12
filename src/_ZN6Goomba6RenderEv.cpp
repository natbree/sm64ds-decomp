//cpp
#pragma opt_common_subs off
struct Vector3 { int x, y, z; };

struct Sub {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(Vector3* v);
};

extern "C" {
extern int data_ov084_02130258[];
extern void _ZN15MaterialChanger6UpdateER15ModelComponents(char* self, void* model);
extern void _ZN8CapEnemy14RenderCapModelEPK7Vector3(char* c, const Vector3* v);
}

extern "C" int _ZN6Goomba6RenderEv(char* c)
{
    int locked;
    volatile Vector3 backup;

    locked = (*(unsigned int*)(c + 0xb0) & 0x40000) != 0;
    if (locked || *(unsigned char*)(c + 0x111) != 0) return 1;

    backup.x = *(int*)(c + 0x80);
    backup.y = *(int*)(c + 0x84);
    backup.z = *(int*)(c + 0x88);

    if (*(int*)(c + 0x10c) == 1) {
        *(int*)(c + 0x80) = (int)(((long long)*(int*)(c + 0x80) * data_ov084_02130258[*(int*)(c + 0x460)] + 0x800) >> 12);
        *(int*)(c + 0x84) = (int)(((long long)*(int*)(c + 0x84) * data_ov084_02130258[*(int*)(c + 0x460)] + 0x800) >> 12);
        *(int*)(c + 0x88) = (int)(((long long)*(int*)(c + 0x88) * data_ov084_02130258[*(int*)(c + 0x460)] + 0x800) >> 12);
    }

    {
        Sub* b = (Sub*)(c + 0x370);
        b->m5((Vector3*)(c + 0x80));
    }

    *(int*)(c + 0x80) = backup.x;
    *(int*)(c + 0x84) = backup.y;
    *(int*)(c + 0x88) = backup.z;
    _ZN15MaterialChanger6UpdateER15ModelComponents(c + 0x3fc, c + 0x378);
    _ZN8CapEnemy14RenderCapModelEPK7Vector3(c, 0);
    return 1;
}
