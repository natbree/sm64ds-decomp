//cpp
typedef short s16;
typedef unsigned short u16;
typedef long long s64;

extern "C" {
extern int data_0208e4b8;
extern int data_0208e3a4;
extern int data_0209b468;
extern s16* data_0209b460;
extern s16* data_0209b45c;
extern signed char data_0209b44c;
extern s16 data_0208e378;
extern int* data_020a4bb8;
extern unsigned char data_0209f2d8;
void _ZN9ActorBaseC1Ev(void* self);
int func_0203b244(void* l, void* n);
void _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(void* self, int a, int b, int c, int d);
}

extern "C" void* _ZN5ActorC2Ev(char* self)
{
    int* entry;
    int b;
    int r3;
    _ZN9ActorBaseC1Ev(self);
    *(void**)self = &data_0208e4b8;
    *(void**)self = &data_0208e3a4;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(char**)(self + 0x58) = self;
    func_0203b244((void*)&data_0209b468, self + 0x50);
    {
        s16* p = data_0209b460;
        if (p != 0) {
            *(int*)(self + 0x5c) = ((int*)p)[0];
            *(int*)(self + 0x60) = ((int*)p)[1];
            *(int*)(self + 0x64) = ((int*)p)[2];
        }
    }
    {
        s16* q = data_0209b45c;
        if (q != 0) {
            *(s16*)(self + 0x8c) = q[0];
            *(s16*)(self + 0x8e) = q[1];
            *(s16*)(self + 0x90) = q[2];
            {
                s16* q2 = data_0209b45c;
                *(s16*)(self + 0x92) = q2[0];
                *(s16*)(self + 0x94) = q2[1];
                *(s16*)(self + 0x96) = q2[2];
            }
        }
    }
    *(signed char*)(self + 0xcc) = data_0209b44c;
    *(s16*)(self + 0xce) = data_0208e378;
    entry = (int*)(((int**)data_020a4bb8)[*(u16*)(self + 0xc)]);
    *(int*)(self + 0xb0) = entry[2];
    b = (data_0209f2d8 == 2);
    if (b != 0)
        r3 = entry[5] + 0x7d0000;
    else
        r3 = entry[5];
    _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(self, entry[3], entry[4], r3, entry[6]);
    return self;
}
