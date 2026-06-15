extern void _ZN12CylinderClsn5ClearEv(void *);
int func_ov080_02124eb0(char *c)
{
    *(int *)(c + 0x98) = 0;
    _ZN12CylinderClsn5ClearEv((char *)c + 0x14c);
    *(int *)(c + 0x370) = 2;
    return 1;
}
