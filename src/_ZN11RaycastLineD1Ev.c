extern void func_0203ac50(void *);
extern void func_ov002_020feab8(void *);
extern void func_020380ec(void *);
extern void func_020354d0(void *);
extern int VT0[];
extern int VT1[];
int *_ZN11RaycastLineD1Ev(int *t)
{
    t[0] = (int)VT0;
    *(int *)((char *)t + 0x10) = (int)VT1;
    func_0203ac50((char *)t + 0x64);
    func_ov002_020feab8((char *)t + 0x38);
    func_020380ec((char *)t + 0x10);
    func_020354d0(t);
    return t;
}
