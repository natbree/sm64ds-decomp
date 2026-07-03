extern int func_ov007_020c9214();

/* NONMATCHING: instruction reorder (div=2). moveq/movne lr order at +0x34/+0x38. */
void func_ov007_020bc3dc(void *c, int i, int a2)
{
    unsigned short **arr;
    unsigned short *p;
    int lr;

    arr = *(unsigned short ***)((char *)c + 0x14);
    p = arr[i];
    if (p == 0) {
        return;
    }
    if (*(unsigned char *)((char *)p + 4) == 0) {
        lr = 0;
    } else {
        lr = 1;
    }
    func_ov007_020c9214(*(void **)((char *)c + 0x18), i, lr, *(unsigned short *)((char *)p + 2), a2, 0x1000);
}