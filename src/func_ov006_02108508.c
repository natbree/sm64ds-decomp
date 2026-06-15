struct S { int w[2]; };
extern struct S G;
void func_ov006_02108508(char *p) { *(struct S *)(p + 0x0) = G; }
