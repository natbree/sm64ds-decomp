extern void _ZN9ModelAnimD1Ev(void *);
extern void _ZN18MovingCylinderClsnD1Ev(void *);
extern void _ZN5ActorD1Ev(void *);
extern int VT0[];
int *func_ov062_0211af38(int *t)
{
    t[0] = (int)VT0;
    _ZN9ModelAnimD1Ev((char *)t + 0x108);
    _ZN18MovingCylinderClsnD1Ev((char *)t + 0xd4);
    _ZN5ActorD1Ev(t);
    return t;
}
