extern void func_ov001_020ab3a0(void *);
extern void _ZN5ModelD1Ev(void *);
extern void func_ov002_020aed18(void *);
extern int VT0[];
int *func_ov002_020aedbc(int *t)
{
    t[0] = (int)VT0;
    func_ov001_020ab3a0((char *)t + 0x164);
    _ZN5ModelD1Ev((char *)t + 0x114);
    func_ov002_020aed18(t);
    return t;
}
