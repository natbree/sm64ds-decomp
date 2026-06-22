extern void func_02039624(char *o);
extern void func_0203821c(int *p, int v);

void _ZN12MeshCollider7SetFileEP8KCL_FileR10CLPS_Block(char *thiz, int arg1, int arg2)
{
    func_02039624(thiz);
    *(int *)(thiz + 0x20) = arg1;
    func_0203821c((int *)(thiz + 0x24), arg2);
    *(int *)(thiz + 0x28) = 0;
    *(int *)(thiz + 0x2c) = 0x1000;
    *(int *)(thiz + 0x30) = 0;
    *(unsigned char *)(thiz + 0x34) = 0;
    *(unsigned char *)(thiz + 0x35) = 0;
    *(int *)(thiz + 0x38) = 0x1000;
    *(int *)(thiz + 0x3c) = 0;
    *(int *)(thiz + 0x40) = 0;
    *(int *)(thiz + 0x44) = -0x1000;
    *(int *)(thiz + 0x48) = 2;
    *(unsigned char *)(thiz + 0x4c) = 1;
    *(unsigned char *)(thiz + 0x4d) = 0;
}
