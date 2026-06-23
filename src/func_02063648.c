typedef unsigned short u16;
typedef unsigned char u8;

extern int data_020a9440[];
extern int func_02061428(int count, ...);
extern void MultiCopy_Int(int *dst, int *src, int len);
extern void _ZN4CP1514FlushDataCacheEjj(unsigned int a, unsigned int b);
extern void func_0206165c(int i, int val);
extern int func_02061558(int a, int b, int c, int d, int e, int f, int g, int h);

int func_02063648(int a0, int *src, int len, int a3, u16 arg5, u16 arg6, u8 arg7)
{
    int ret = func_02061428(2, 7, 9);
    if (ret != 0) return ret;
    if (src == 0) return 6;
    if ((unsigned int)len > 0x70) return 6;
    MultiCopy_Int(src, data_020a9440, len);
    _ZN4CP1514FlushDataCacheEjj((unsigned int)data_020a9440, len);
    func_0206165c(0x18, a0);
    ret = func_02061558(0x18, 6, (int)data_020a9440, len, a3, arg5, arg6, arg7);
    if (ret == 0) ret = 2;
    return ret;
}
