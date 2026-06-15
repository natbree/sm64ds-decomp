extern void _ZN10ClsnResultD1Ev(void *);
extern void func_0203ac1c(void *);
extern void func_020380ec(void *);
extern void func_020354d0(void *);
extern int VT0[];
extern int VT1[];
extern int VT2[];
int *_ZN10SphereClsnD1Ev(int *t)
{
    t[0] = (int)VT0;
    *(int *)((char *)t + 0x10) = (int)VT1;
    *(int *)((char *)t + 0x38) = (int)VT2;
    _ZN10ClsnResultD1Ev((char *)t + 0xc4);
    _ZN10ClsnResultD1Ev((char *)t + 0x9c);
    _ZN10ClsnResultD1Ev((char *)t + 0x74);
    func_0203ac1c((char *)t + 0x38);
    func_020380ec((char *)t + 0x10);
    func_020354d0(t);
    return t;
}
