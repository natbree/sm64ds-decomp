extern int GetOwnerLanguage(void);
extern void *LoadFile(int id);
extern void func_0201cb2c(void);
extern void *data_0209d6fc;

void func_0201fe08(void)
{
    if (GetOwnerLanguage() == 5) {
        data_0209d6fc = LoadFile(0x435);
    } else if (GetOwnerLanguage() == 4) {
        data_0209d6fc = LoadFile(0x434);
    } else if (GetOwnerLanguage() == 3) {
        data_0209d6fc = LoadFile(0x433);
    } else if (GetOwnerLanguage() == 2) {
        data_0209d6fc = LoadFile(0x432);
    } else {
        data_0209d6fc = LoadFile(0x431);
    }
    func_0201cb2c();
}
