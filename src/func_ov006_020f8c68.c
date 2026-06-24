void func_ov006_020f7c10(char* p);
void func_ov006_020c1604(char* c, int unused, short a2, int a3);
void func_ov004_020b66d4(char* p);

extern int data_ov006_0213d564;
extern int func_020bc7d4;

void func_ov006_020f8c68(char* c)
{
    func_ov006_020f7c10(c + 0x51a8);
    data_ov006_0213d564 = 0;
    *(short*)(c + 0x60ae) = 0;
    *(short*)(c + 0x511e) = 1;
    func_ov006_020c1604(c + 0x4f38, 4, 4, (int)(c + 0x60ae));
    *(short*)(c + 0x4f52) = 1;
    *(short*)(c + 0x60aa) = 0;
    *(short*)(c + 0x60a8) = 1;
    func_ov004_020b66d4(c + 0x6000);
    func_020bc7d4 = 1;
}
