//cpp
extern "C" {
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void*,unsigned int,int,int,unsigned int);
int _ZN6Player13St_Crawl_InitEv(char* c){
  *(char*)(c+0x6e3)=3;
  _ZN6Player7SetAnimEji5Fix12IiEj(c,0x64,0x40000000,0x1000,0);
  return 1;
}
}
