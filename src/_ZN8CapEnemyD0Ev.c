extern void func_ov001_020ab3a0(void *);
extern void _ZN5ModelD1Ev(void *);
extern void func_ov002_020aed18(void *);
extern void _ZN6Memory10DeallocateEPvP4Heap(void *, void *);
extern int VT0[];
extern void *G0;
int *_ZN8CapEnemyD0Ev(int *t)
{
    t[0] = (int)VT0;
    func_ov001_020ab3a0((char *)t + 0x164);
    _ZN5ModelD1Ev((char *)t + 0x114);
    func_ov002_020aed18(t);
    _ZN6Memory10DeallocateEPvP4Heap(t, G0);
    return t;
}
