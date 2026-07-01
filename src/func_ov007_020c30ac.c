struct Vec3 { int x, y, z; };
extern void SubVec3(struct Vec3 *a, struct Vec3 *b, struct Vec3 *c);
int func_ov007_020c30ac(struct Vec3 *arr, int count, struct Vec3 *target, int arg4, int *out)
{
    struct Vec3 diff; long long d2; int i; int bestIdx;
    long long best = 0x7fffffffffffffffLL;
    for (i = 0; i < count; i++) {
        SubVec3(arr, target, &diff);
        d2 = (long long)diff.x * diff.x + (long long)diff.y * diff.y + (long long)diff.z * diff.z;
        arr = (struct Vec3 *)((char *)arr + 0xc);
        if (d2 < best) { bestIdx = i; best = d2; }
    }
    if (arg4 < 0 || (long long)arg4 * arg4 >= best) {
        unsigned short ime = *(volatile unsigned short *)0x4000208;
        *(volatile unsigned short *)0x4000208 = 0;
        *(volatile unsigned short *)0x40002b0 = 1;
        *(volatile unsigned long long *)0x40002b8 = (unsigned long long)best << 2;
        *(volatile unsigned short *)0x4000208;
        *(volatile unsigned short *)0x4000208 = ime;
        if (out != 0) { while (*(volatile unsigned short *)0x40002b0 & 0x8000) ; *out = (*(volatile int *)0x40002b4 + 1) >> 1; }
        return bestIdx;
    }
    return -1;
}
