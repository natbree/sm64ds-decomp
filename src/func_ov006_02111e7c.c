typedef unsigned char u8;

extern void func_ov006_02111e48(void* o);

void func_ov006_02111e7c(char* c)
{
    *(u8*)(c + 0x121) = 1;
    func_ov006_02111e48(c);
}
