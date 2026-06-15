struct S { int w[1]; };
extern struct S G;
void func_ov006_020ccd64(char *p) { *(struct S *)(p + 0x20) = G; }
