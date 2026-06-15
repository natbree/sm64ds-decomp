struct S { int w[2]; };
extern struct S G;
void func_ov006_020cdad0(char *p) { *(struct S *)(p + 0x0) = G; }
