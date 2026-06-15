extern void func_02035514(void *);
extern void _ZN10SphereClsnC1Ev(void *);
extern void _ZN11RaycastLineC1Ev(void *);
extern int VT0[];
int *_ZN12WithMeshClsnC1Ev(int *t)
{
    func_02035514(t);
    t[0] = (int)VT0;
    _ZN10SphereClsnC1Ev((char *)t + 0x20);
    _ZN11RaycastLineC1Ev((char *)t + 0x134);
    return t;
}
