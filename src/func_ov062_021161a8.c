// NONMATCHING: instruction reorder (div=2). beq/add r3 order at +0x5c/+0x60.
// if(1) block required for correct function size (0x90 vs 0x8c without it).
extern int _ZNK9Animation12WillHitFrameEi(char *anim, int f);
extern int func_ov002_020db54c(int p, int a, int b, int s);
extern int func_02012694(int id, void *pos);
extern int _ZN9Animation8FinishedEv(char *anim);
extern int func_ov062_02116cd8(char *c, void *p);
extern int data_ov062_0211ded0[];

int func_ov062_021161a8(char *c)
{
    int new_var;
    int *q;

    if (*(int *)(c + 0x3f8) != 0 && _ZNK9Animation12WillHitFrameEi(c + 0x350, 0x14)) {
        func_ov002_020db54c(*(int *)(c + 0x3f8), 0x28000, 0x50000, *(short *)(c + 0x8e));
        *(int *)(c + 0x3f8) = 0;
        func_02012694(0x126, c + 0x74);
    }
    if (1) {
        new_var = _ZN9Animation8FinishedEv(c + 0x350);
        q = (int *)(c + 0x128);
    }
    if (new_var) {
        *q &= ~2;
        func_ov062_02116cd8(c, data_ov062_0211ded0);
    }
    return 1;
}