extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN8PlatformC2Ev(void *);
extern void _ZN12WithMeshClsnC1Ev(void *);
extern int VT0[];
int *func_ov002_020b910c(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(1268);
    if (p) {
        _ZN8PlatformC2Ev(p);
        p[0] = (int)VT0;
        _ZN12WithMeshClsnC1Ev((char *)p + 0x320);
    }
    return p;
}
