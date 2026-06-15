extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN5EnemyC2Ev(void *);
extern void _ZN9ModelAnimC1Ev(void *);
extern void _ZN18TextureTransformerC1Ev(void *);
extern int VT0[];
int *func_ov026_021121bc(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(444);
    if (p) {
        _ZN5EnemyC2Ev(p);
        p[0] = (int)VT0;
        _ZN9ModelAnimC1Ev((char *)p + 0x114);
        _ZN18TextureTransformerC1Ev((char *)p + 0x178);
    }
    return p;
}
