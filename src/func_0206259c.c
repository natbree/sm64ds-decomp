extern int func_02061548(void);
extern int func_02061428(int a, int b);
extern void func_0206165c(int i, int val);
extern int func_02061558(int a, int b, int c);

int func_0206259c(int a, int b)
{
    int r;
    func_02061548();
    r = func_02061428(1, 9);
    if (r != 0)
        return r;
    func_0206165c(0x23, a);
    r = func_02061558(0x23, 1, b);
    if (r == 0)
        r = 2;
    return r;
}
