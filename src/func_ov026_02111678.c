extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN5ActorC2Ev(void *);
extern void _ZN5ModelC1Ev(void *);
extern void _ZN25MovingCylinderClsnWithPosC1Ev(void *);
extern void _ZN7PathPtrC1Ev(void *);
extern void _ZN11ShadowModelC1Ev(void *);
extern int VT0[];
int *func_ov026_02111678(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(484);
    if (p) {
        _ZN5ActorC2Ev(p);
        p[0] = (int)VT0;
        _ZN5ModelC1Ev((char *)p + 0xd4);
        _ZN25MovingCylinderClsnWithPosC1Ev((char *)p + 0x124);
        _ZN7PathPtrC1Ev((char *)p + 0x164);
        _ZN11ShadowModelC1Ev((char *)p + 0x188);
    }
    return p;
}
