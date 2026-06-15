extern void *_ZN9ActorBasenwEj(unsigned);
extern void _ZN9ActorBaseC1Ev(void *);
extern int VT0[];
extern int VT1[];
int *_ZN7MinimapC1Ev(void)
{
    int *p = (int *)_ZN9ActorBasenwEj(600);
    if (p) {
        _ZN9ActorBaseC1Ev(p);
        p[0] = (int)VT0;
        p[0] = (int)VT1;
    }
    return p;
}
