typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern int func_0206c90c(u64 x);
extern int func_0206c8b4(u64 x);

#define RD(p) ((((u32)(p)) & 1) ? ((*(u16 *)((u32)(p) - 1) & 0xff00) >> 8) : (*(u16 *)(p) & 0xff))

#define WR(p, v) \
    do { \
        if (((u32)(p)) & 1) \
            *(u16 *)((u32)(p) - 1) = (*(u16 *)((u32)(p) - 1) & 0xff) | (((v) & 0xff) << 8); \
        else \
            *(u16 *)(p) = (*(u16 *)(p) & 0xff00) | ((v) & 0xff); \
    } while (0)

#pragma optimize_for_size on
#pragma opt_common_subs off
u64 func_0206bdb4(u64 x, int flag)
{
    int sign;
    int e;
    int n;
    u64 res;
    int v;
    int b;
    int j;
    u8 * q;
    u64 frac;
    u32 c;
    int f;
    u64 m;
    u64 quot;
    int d;
    u32 rem;
    int k;
    u64 t;
    int i;

    sign = func_0206c90c(x);
    e = func_0206c8b4(x);

    m = 0;
    m |= 0x10;
    q = (u8 *)&x + 6;
    m |= RD(q) & 0xf;
    for (j = 5; j >= 0; j--) {
        q = (u8 *)&x + j;
        m <<= 8;
        m |= RD(q);
    }

    d = e - 0x3fd;
    if (e >= 3) e -= 3; else e = 0;
    quot = 0;
    rem = 0;
    i = 0;
    m |= 0x0010000000000000ULL;
    f = (flag == 0);
    while ((c = (d <= 0x35 && f)), (i < (c ? d : 0x35))) {
        quot <<= 1;
        rem <<= 1;
        t = m;
        k = 0;
        for (n = 0x34 - i; k < n; k++)
            t >>= 1;
        if ((t & 1) != 0)
            rem++;
        if (rem >= 5) {
            quot += 1;
            rem -= 5;
        }
        i++;
    }
    if (rem != 0)
        quot += 1;
    j = 0x35 - i;
    for (k = 0; k < j; k++)
        quot <<= 1;
    if (d >= 3) d -= 3; else d = 0;
    m -= quot;
    if (flag == 0) {
        v = 0x35 - d;
        for (k = 0; k < v; k++)
            m >>= 1;
        for (i = 0; i < v; i++)
            m <<= 1;
    }
    while (((m >> 52) & 1) == 0 && m != 0) {
        e--;
        m <<= 1;
    }
    frac = m & 0xFFFFFFFFFFFFFULL;
    if (frac == 0) {
        if (e < 0x3ff) {
            if (flag == 0) {
                sign = 0;
                e = 0;
            }
        }
    }
    res = 0;
    q = (u8 *)&res + 7;
    v = RD(q) | (sign << 7);
    q = (u8 *)&res + 7;
    WR(q, v);
    q = (u8 *)&res + 7;
    v = RD(q) | (e >> 4);
    q = (u8 *)&res + 7;
    WR(q, v);
    q = (u8 *)&res + 6;
    v = RD(q) | ((e & 0xf) << 4);
    q = (u8 *)&res + 6;
    WR(q, v);
    for (k = 6; k >= 0; k--) {
        t = frac;
        for (n = 0; n < k << 3; n++)
            t >>= 1;
        q = (u8 *)&res + k;
        v = ((u32)t & 0xff) | RD(q);
        WR(q, v);
    }
    return res;
}
