extern int func_ov006_020c1718(int* p);
extern void func_ov004_020b0aa0(int n);

int func_ov006_020f5250(char* c) {
    if (*(int*)(c + 0x5314) == 3 && *(int*)(c + 0x5318) == 0) {
        if (func_ov006_020c1718((int*)(c + 0x4f38)) == 0) return 0;
        *(int*)(c + 0x5318) = 1;
        func_ov004_020b0aa0(0x1d);
    }
    return *(int*)(c + 0x5314) == 4;
}
