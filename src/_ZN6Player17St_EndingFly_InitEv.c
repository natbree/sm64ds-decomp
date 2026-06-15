extern int func_ov002_020c9e40(void* c);
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void* c, unsigned int a, int b, int f, unsigned int g);
int _ZN6Player17St_EndingFly_InitEv(char* c){
  func_ov002_020c9e40(c);
  *(unsigned char*)(c+0x6f6)=1;
  *(unsigned char*)(c+0x6e6)=0;
  *(unsigned char*)(c+0x6e5)=*(unsigned char*)(c+0x6e6);
  _ZN6Player7SetAnimEji5Fix12IiEj(c,0x54,0x40000000,0x1000,0);
  return 1;
}
