extern void _Z14ApproachLinearRiii(int* p, int value, int speed);
extern int _ZN6Player12FinishedAnimEv(void* c);
extern void _ZN6Player11ChangeStateERNS_5StateE(void* c, void* state);
extern void func_ov002_020bedd4(char* self);
extern short data_02082214[];
extern char data_ov002_0211013c[];

int _ZN6Player24St_BowserEarthquake_MainEv(char* c)
{
    if (*(unsigned char*)(c+0x6e3) == 0) {
        _Z14ApproachLinearRiii((int*)(c+0x98), 0, 0x1800);
        if (_ZN6Player12FinishedAnimEv(c)) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
        }
    } else {
        int t = *(unsigned short*)(c+0x6a4);
        int m = t % 16;
        int idx = (unsigned short)(short)(m << 12) >> 4;

        *(int*)(c+0x98) = 0;

        int radius = 0x4000 + ((0x6000 - ((t << 12) / 8)) << 3);

        *(int*)(c+0xa8) = 0;

        int sinVal = data_02082214[idx * 2];

        if (sinVal >= 0) {
            *(int*)(c+0x60) = *(int*)(c+0x644) + (int)(((long long)radius * sinVal + 0x800) >> 12);
        } else {
            *(int*)(c+0x60) = *(int*)(c+0x644) - (int)(((long long)radius * sinVal + 0x800) >> 12);
        }

        if (*(unsigned short*)(c+0x6a4) == 0) {
            _ZN6Player11ChangeStateERNS_5StateE(c, data_ov002_0211013c);
        }
    }

    func_ov002_020bedd4(c);
    return 1;
}
