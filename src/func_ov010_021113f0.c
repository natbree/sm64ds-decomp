extern void Matrix4x3_FromTranslation(void *m, int x, int y, int z);
extern void Matrix4x3_ApplyInPlaceToRotationY(void *m, short ang);
extern void Matrix4x3_ApplyInPlaceToRotationZ(void *m, short ang);
extern void _ZN18MovingMeshCollider9TransformERK9Matrix4x3s(void *self, void *m, short s);
struct M { int w[12]; };
extern struct M data_020a0e68;
void func_ov010_021113f0(char *c) {
    Matrix4x3_FromTranslation(&data_020a0e68, *(int*)(c+0x5c), *(int*)(c+0x60), *(int*)(c+0x64));
    Matrix4x3_ApplyInPlaceToRotationY(&data_020a0e68, *(short*)(c+0x8e));
    Matrix4x3_ApplyInPlaceToRotationZ(&data_020a0e68, *(short*)(c+0x90));
    *(struct M*)(c+0x370) = data_020a0e68;
    _ZN18MovingMeshCollider9TransformERK9Matrix4x3s(c+0x124, c+0x370, *(short*)(c+0x8e));
}
