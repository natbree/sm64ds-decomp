extern void _ZN9Animation7AdvanceEv(void *);
extern void func_ov100_021437d4(void *);
extern void func_ov100_0214344c(void *);
extern void func_ov100_021435e8(void *);
int func_ov100_02143aa4(char *c)
{
    *(int *)(c + 0x368) = 4096;
    _ZN9Animation7AdvanceEv((char *)c + 0x35c);
    func_ov100_021437d4(c);
    func_ov100_0214344c(c);
    func_ov100_021435e8(c);
    return 1;
}
