//cpp
extern "C" {
extern int func_ov002_020bd8c0(void*,int);
int _ZN6Player15St_Swim_CleanupEv(char* c){
  if(*(unsigned char*)(c+0x6f7)!=0){
    *(char*)(c+0x6f7)=0;
    func_ov002_020bd8c0(c,0x33);
  }
  return 1;
}
}
