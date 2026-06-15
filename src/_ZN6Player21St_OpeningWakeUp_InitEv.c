extern int _ZN6Player7SetAnimEji5Fix12IiEj(void* c, unsigned int a, int b, int f, unsigned int g);
int _ZN6Player21St_OpeningWakeUp_InitEv(char* c){
  *(unsigned char*)(c+0x721)=0;
  _ZN6Player7SetAnimEji5Fix12IiEj(c,0xb2,0x40000000,0x1000,0);
  *(unsigned char*)(c+0x6e3)=0;
  return 1;
}
