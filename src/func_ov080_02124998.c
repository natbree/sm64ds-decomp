extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN5EnemyC2Ev(void *);
extern void _ZN5ModelC1Ev(void *);
extern void _ZN18MovingCylinderClsnC1Ev(void *);
extern void _ZN12WithMeshClsnC1Ev(void *);
extern int VT0[];
int *func_ov080_02124998(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(852);
    if (p) {
        _ZN5EnemyC2Ev(p);
        p[0] = (int)VT0;
        _ZN5ModelC1Ev((char *)p + 0x110);
        _ZN18MovingCylinderClsnC1Ev((char *)p + 0x160);
        _ZN12WithMeshClsnC1Ev((char *)p + 0x194);
    }
    return p;
}
