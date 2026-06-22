extern void func_ov004_020b0104(int a, int b, int c, int d, int e, int f);
extern int data_ov006_02138c3c[];
void func_ov006_02108cc0(char *c) {
    if (*(unsigned char *)(c + 0x32) == 6) return;
    func_ov004_020b0104(*data_ov006_02138c3c,
                        *(int *)c >> 0xc,
                        *(int *)(c + 4) >> 0xc,
                        -1,
                        *(int *)(c + 0x28),
                        0);
    *(int *)(c + 0x28) = 1;
}
