extern void _ZN12CylinderClsn5ClearEv(void *);
int func_ov077_021258dc(char *c)
{
    *(int *)(c + 0x98) = 0;
    _ZN12CylinderClsn5ClearEv((char *)c + 0x1b0);
    *(int *)(c + 0x3d8) = 3;
    return 1;
}
