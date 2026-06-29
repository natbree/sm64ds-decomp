//cpp
// func_ov098_0213b6e0 at 0x0213b6e0
// Matched byte-for-byte with mwccarm 1.2/sp2p3 (ov098).
struct Vector3 { int x, y, z; };

extern "C" {
void* _ZN5Actor10FindWithIDEj(unsigned int id);
void _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(
    void* thiz, const Vector3* vec, unsigned int a, int fix,
    unsigned int b, unsigned int c, unsigned int d);
void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(
    unsigned int kind, int x, int y, int z);
void func_ov098_0213b63c(char* c);
}

extern "C" int func_ov098_0213b6e0(char* c)
{
    unsigned int id = *(unsigned int*)(c + 0x134);
    void* a;
    unsigned short mid;
    int t;

    if (id != 0) {
        a = _ZN5Actor10FindWithIDEj(id);
        if (a != 0) {
            mid = *(unsigned short*)((char*)a + 0xc);
            t = (mid == 0xbf);
            if (t != false) {
                Vector3 vec;
                vec.x = *(int*)(c + 0x5c);
                vec.y = *(int*)(c + 0x60);
                vec.z = *(int*)(c + 0x64);
                _ZN6Player4HurtERK7Vector3j5Fix12IiEjjj(a, &vec, 1, 0xc000, 1, 0, 1);
                if (*(int*)(c + 0x3c8) == 1) {
                    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(
                        0x1c, *(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
                    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(
                        0x1d, *(int*)(c + 0x5c), *(int*)(c + 0x60), *(int*)(c + 0x64));
                    func_ov098_0213b63c(c);
                    return 1;
                }
            } else {
                t = (mid == 0xce);
                if (t != false) {
                    if (*(int*)(c + 0x3c8) == 1) {
                        func_ov098_0213b63c(c);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}