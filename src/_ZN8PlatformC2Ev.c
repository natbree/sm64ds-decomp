extern void _ZN5ActorC2Ev(void *);
extern void _ZN5ModelC1Ev(void *);
extern void _ZN18MovingMeshColliderC1Ev(void *);
extern int VT0[];
int *_ZN8PlatformC2Ev(int *t)
{
    _ZN5ActorC2Ev(t);
    t[0] = (int)VT0;
    _ZN5ModelC1Ev((char *)t + 0xd4);
    _ZN18MovingMeshColliderC1Ev((char *)t + 0x124);
    return t;
}
