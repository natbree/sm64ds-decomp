extern void func_ov001_020ab110(void *);
extern void _ZN6Memory16operator_delete2EPv(void *);
extern int VT0[];
int *func_ov001_020ab374(int *t)
{
    t[0] = (int)VT0;
    func_ov001_020ab110(t);
    _ZN6Memory16operator_delete2EPv(t);
    return t;
}
