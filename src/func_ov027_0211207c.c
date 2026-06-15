extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN8PlatformC2Ev(void *);
extern void _ZN9ModelAnimC1Ev(void *);
extern void _ZN15TextureSequenceC1Ev(void *);
extern void _ZN18MovingCylinderClsnC1Ev(void *);
extern int VT0[];
int *func_ov027_0211207c(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(988);
    if (p) {
        _ZN8PlatformC2Ev(p);
        p[0] = (int)VT0;
        _ZN9ModelAnimC1Ev((char *)p + 0x320);
        _ZN15TextureSequenceC1Ev((char *)p + 0x384);
        _ZN18MovingCylinderClsnC1Ev((char *)p + 0x398);
    }
    return p;
}
