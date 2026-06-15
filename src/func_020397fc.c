extern void func_02038224(void *);
extern void func_02039658(void *);
extern int VT0[];
int *func_020397fc(int *t)
{
    t[0] = (int)VT0;
    func_02038224((char *)t + 0x24);
    func_02039658(t);
    return t;
}
