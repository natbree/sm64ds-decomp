//cpp
struct C;
typedef void (C::*PMF)();
struct C {
    char pad[0x5004];
    PMF pmf;
};
extern "C" {
extern int data_ov006_02140588;
extern void func_ov006_02120c40(void);
extern void func_ov006_0212157c(void *c);
extern void func_ov006_021209ac(short *o);
extern void func_ov004_020adb1c(int self);
}

extern "C" int func_ov006_021214f8(char *c)
{
    int saved = data_ov006_02140588;
    func_ov006_02120c40();
    (((C *)c)->*(((C *)c)->pmf))();
    func_ov006_0212157c(c);
    func_ov006_021209ac((short *)(c + 0x5d84));
    if (saved != data_ov006_02140588)
        func_ov004_020adb1c(data_ov006_02140588);
    return 1;
}
