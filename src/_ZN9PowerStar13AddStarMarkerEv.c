typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern void SetStarMarker(int i, int v1, int v2);
extern int IsStarCollectedInCurLevel(int starID);
extern void FUN_0202a130(void);
extern int data_0209f40c[];
extern u8 data_0209f208;

struct Bits {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
};

void _ZN9PowerStar13AddStarMarkerEv(char* c)
{
    s8 i;
    if (*(signed char*)(c + 0x498) >= 0) return;
    for (i = 0; i < 0xc; i++) {
        if (data_0209f40c[(int)i] != 0) continue;

        if (*(u8*)(c + 0x49a) == 0) {
            if (((struct Bits*)(c + 0x4a2))->b2) {
                SetStarMarker((int)i, (int)c, 3);
            } else {
                SetStarMarker((int)i, (int)c, 2);
            }
        } else {
            if (*(u8*)(c + 0x49a) == 2) {
                if (((struct Bits*)(c + 0x4a2))->b2) goto setmark;
                {
                    int f43c = *(int*)(c + 0x43c);
                    if (f43c == 5 || f43c == 7) {
                        if (IsStarCollectedInCurLevel(*(u8*)(c + 0x49d)) != 0) goto setmark;
                    }
                }
                goto skipmark;
            setmark:
                *(u8*)(c + 0x49a) = 3;
            skipmark:;
            }
            SetStarMarker((int)i, (int)c, *(u8*)(c + 0x49a));
        }

        *(s8*)(c + 0x498) = i;
        if (*(int*)(c + 0x440) == 9) {
            if (data_0209f208 == 0) return;
        }
        FUN_0202a130();
        return;
    }
}
