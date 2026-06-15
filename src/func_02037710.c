extern void func_0203ac50(void *);
extern void func_ov002_020feab8(void *);
extern void func_020380ec(void *);
extern void func_020354d0(void *);
extern void _ZN6Memory16operator_delete2EPv(void *);
extern int VT0[];
extern int VT1[];
int *func_02037710(int *t)
{
    t[0] = (int)VT0;
    *(int *)((char *)t + 0x10) = (int)VT1;
    func_0203ac50((char *)t + 0x64);
    func_ov002_020feab8((char *)t + 0x38);
    func_020380ec((char *)t + 0x10);
    func_020354d0(t);
    _ZN6Memory16operator_delete2EPv(t);
    return t;
}
