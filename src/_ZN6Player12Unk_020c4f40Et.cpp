//cpp
extern "C" {
struct State;
extern State data_ov002_0211046c;
extern int _ZN6Player7IsStateERNS_5StateE(void* c, State* st);
int _ZN6Player12Unk_020c4f40Et(char* c, unsigned short x){
  if(_ZN6Player7IsStateERNS_5StateE(c,&data_ov002_0211046c) && *(unsigned char*)(c+0x6e3)==3){
    *(unsigned short*)(c+0x6a6)=x;
    *(unsigned char*)(c+0x6e3)=5;
    return 1;
  }
  return 0;
}
}
