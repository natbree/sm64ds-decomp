typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Vec { s32 x, y, z; };

extern void func_ov002_020aefa4(char *self);
extern void _ZN5Sound9PlayBank3EjRK7Vector3(u32 id, struct Vec *v);
extern void func_ov002_020aefb8(char *self);
extern void func_ov002_020afde4(char *c);
extern void func_ov002_020aeee4(char *c);
extern void func_ov002_020af3a8(char *c);
extern int func_ov002_020af248(char *c, int n);
extern void func_ov002_020af474(char *o);

void func_ov002_020afa98(char *c)
{
    switch (*(s32 *)(c + 0x388)) {
    case 0:
        *(u8 *)(c + 0x38e) = 0;
        if (*(s32 *)(c + 0x390) != 0)
            return;
        *(u32 *)(c + 0xa8) = 0x28000;
        *(s32 *)(c + 0x388) = 3;
        *(u8 *)(c + 0x38e) = 1;
        func_ov002_020aefa4(c);
        _ZN5Sound9PlayBank3EjRK7Vector3(0x68, (struct Vec *)(c + 0x74));
        *(u32 *)(((long long)(int)(c + 0xb0)) & 0xFFFFFFFFFFFFFFFFLL) &= ~1;
        return;
    case 1:
        func_ov002_020aefb8(c);
        func_ov002_020afde4(c);
        func_ov002_020aeee4(c);
        return;
    case 2:
        func_ov002_020aefb8(c);
        func_ov002_020af3a8(c);
        func_ov002_020af248(c, 0x1e);
        return;
    case 3:
        func_ov002_020aefb8(c);
        if (*(u16 *)(c + 0x100) > 0x11) {
            func_ov002_020aeee4(c);
        }
        func_ov002_020af474(c);
        if (*(u16 *)(c + 0x100) != 0x25)
            return;
        *(u32 *)(((long long)(int)(c + 0x128)) & 0xFFFFFFFFFFFFFFFFLL) &= ~1;
        *(s32 *)(c + 0x388) = 1;
        *(u32 *)(c + 0x98) = 0x8000;
        return;
    }
}
