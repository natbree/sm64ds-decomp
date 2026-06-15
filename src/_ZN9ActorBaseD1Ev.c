extern void func_020440e8(void *);
extern int VT0[];
int *_ZN9ActorBaseD1Ev(int *t)
{
    t[0] = (int)VT0;
    func_020440e8((char *)t + 0x38);
    func_020440e8((char *)t + 0x28);
    return t;
}
