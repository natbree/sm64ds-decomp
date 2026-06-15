extern void func_02038224(void *);
extern void func_02039658(void *);
extern void _ZN6Memory16operator_delete2EPv(void *);
extern int VT0[];
int *_ZN12MeshColliderD0Ev(int *t)
{
    t[0] = (int)VT0;
    func_02038224((char *)t + 0x24);
    func_02039658(t);
    _ZN6Memory16operator_delete2EPv(t);
    return t;
}
