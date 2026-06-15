struct S { int w[2]; };
extern struct S G;
void func_ov006_020c85a0(char *p) { *(struct S *)(p + 0x3c) = G; }
