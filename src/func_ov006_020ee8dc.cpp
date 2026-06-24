//cpp
extern "C" int data_ov006_02140428;
extern "C" short _Z15ApproachLinear2Rsss(short &r, short b, short c);
extern "C" void func_ov006_020c8a9c(int a0, int a1);
extern "C" void func_ov006_020c72dc(void);
extern "C" void func_02012790(int a0);

extern "C" int func_ov006_020ee8dc(char *thiz, int sel)
{
    if (sel == 0) {
        if (*(unsigned int*)(thiz + 0xbc) % 5 == 4) {
            if (_Z15ApproachLinear2Rsss(*(short*)(thiz + 0x5014), 0, 1) != 0) {
                if ((&data_ov006_02140428)[0] < 3) {
                    func_ov006_020c72dc();
                    func_02012790(0x26);
                    *(short*)(thiz + 0x5000 + 0x14) = 0x3c;
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }
    func_ov006_020c8a9c(0, 0);
    return 1;
}
