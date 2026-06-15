struct S { int w[2]; };
extern struct S G;
void func_ov006_020c4d20(char *p) { *(struct S *)(p + 0x30) = G; }
