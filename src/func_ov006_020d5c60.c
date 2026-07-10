typedef unsigned short u16;
typedef unsigned char u8;

extern void SetBg2Offset(int a, int b);

void func_ov006_020d5c60(char* c)
{
    *(int*)(c + 0x62dc) = 0;
    *(u8*)(c + 0x62f4) = 0;
    *(u16*)(c + 0x62f2) = 0;
    SetBg2Offset(0, 0);
}
