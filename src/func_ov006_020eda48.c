extern void func_ov004_020adb1c(int self);
extern void func_ov006_020ea8e0(void);
extern unsigned char func_ov006_020ea658(void);
extern void func_ov006_020ed8a4(void* self);
extern char* func_020beb68;

void func_ov006_020eda48(char* c, int state)
{
    if (state == 1) {
        unsigned int v = *(unsigned int*)(c + 0xbc) + 1;
        *(unsigned int*)(c + 0xbc) = v;
        if (*(unsigned int*)(c + 0xbc) > 0x270e) *(unsigned int*)(c + 0xbc) = 0x270e;
    } else if (state == 0x12) {
        *(unsigned int*)(c + 0xbc) = 0;
        if (*(unsigned int*)(c + 0xbc) > 0x270e) *(unsigned int*)(c + 0xbc) = 0x270e;
        if (func_020beb68 != 0) *(int*)(func_020beb68 + 0xb4) = 0;
        func_ov004_020adb1c(*(int*)(c + 0xb4));
        *(int*)(c + 0x4670) = 0x14;
    } else {
        int v = *(int*)(c + 0xbc);
        if (func_020beb68 != 0) *(int*)(func_020beb68 + 0xb4) = v;
        *(int*)(c + 0x4670) = 0x14;
    }
    func_ov006_020ea8e0();
    func_ov006_020ea658();
    func_ov006_020ed8a4(c);
}
