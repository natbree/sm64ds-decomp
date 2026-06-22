extern int func_02061428(int a, int b);
extern void func_0206165c(int i, int val);
extern int *func_02061548(void);
extern int func_02061558(int a, int b, int c, int d, int e);

int func_02062380(int x)
{
    int r;
    int *p;
    r = func_02061428(1, 0);
    if (r) return r;
    func_0206165c(3, x);
    p = func_02061548();
    r = func_02061558(3, 3, p[0], p[1], p[4]);
    if (r == 0) return 2;
    return r;
}
