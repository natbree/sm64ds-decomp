//cpp
struct Node {
    virtual void m0();
    Node *next;
    char pad[0x18];
    int f20;
};

extern "C" void func_ov006_020c0aa8(void *c);
extern "C" void func_ov004_020b1ea4(int a, int b, int c, int d, int e, int f, int g);
extern "C" int  func_ov004_020afa20(int a0, int a1, int a2, int a3, int a4);
extern "C" void func_ov004_020b0d8c(void *c, int arg1, int arg2);
extern "C" void func_ov006_020c1804(void *c);

extern short data_ov006_02142564;
extern int data_ov006_02133f18;
extern Node *data_ov006_02142578;

extern "C" int func_ov006_020f9ffc(char *c)
{
    short v;
    Node *n6;
    int i5;
    int i6;
    Node *n5;

    func_ov006_020c0aa8(c + 0x4660);

    v = data_ov006_02142564;
    if (v > 0x270f)
        v = 0x270f;
    func_ov004_020b1ea4(0xe8, 0x28, v, 1, -1, 0, 0);

    func_ov004_020afa20(data_ov006_02133f18, 0xe8, 0x18, -1, -1);

    if (*(short *)(c + 0x5928) == 5)
        func_ov004_020b0d8c(c, 0xe0, 0xa0);

    n6 = data_ov006_02142578;
    for (i5 = 0; i5 < 0x14; i5++) {
        if (n6 == 0)
            break;
        if (n6->f20 > 0)
            n6->m0();
        n6 = n6->next;
    }

    n5 = data_ov006_02142578;
    for (i6 = 0; i6 < 0x14; i6++) {
        if (n5 == 0)
            break;
        if (n5->f20 == 0)
            n5->m0();
        n5 = n5->next;
    }

    func_ov006_020c1804(c + 0x4f38);
    return 1;
}
