typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern int func_020614d0(void);
extern void func_0206165c(int i, int val);
extern int func_02061558(int a, int b, int c, int d, int e);

int func_02063574(int a, int b, int c, int d) {
    int r = func_020614d0();
    if (r != 0) return r;
    func_0206165c(0x1d, a);
    r = func_02061558(0x1d, 3, b, c, d);
    if (r == 0) return 2;
    return r;
}
