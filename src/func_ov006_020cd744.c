extern void ApproachLinear(int* a, int b, int c);
extern int ApproachLinear2(int* a, int b, int c);
extern int data_ov006_02140828;

void func_ov006_020cd744(char* c) {
    ApproachLinear((int*)(c + 0x68), 0x1200, 0x80);
    ApproachLinear((int*)(c + 0x70), 0x1200, 0x80);
    ApproachLinear((int*)(c + 0x6c), 0x20000, 0x400);
    if (ApproachLinear2((int*)(c + 0x9c), 0, 1) == 0) return;
    *(int*)(c + 0x84) = 0;
    ApproachLinear(&data_ov006_02140828, 0, 1);
}
