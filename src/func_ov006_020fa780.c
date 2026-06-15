extern int VT[];
extern void func_ov004_020b29c0(void *);
extern void _ZN6Memory10DeallocateEPvP4Heap(void *, void *);
extern void *HEAP;
int *func_ov006_020fa780(int *t)
{
    t[0] = (int)VT;
    func_ov004_020b29c0(t);
    _ZN6Memory10DeallocateEPvP4Heap(t, HEAP);
    return t;
}
