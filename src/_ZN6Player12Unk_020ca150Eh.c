struct State { int a; int b; };
extern int _ZN6Player7IsStateERNS_5StateE(void *c, struct State *s);
extern int _ZN6Player11ChangeStateERNS_5StateE(void *c, struct State *s);
extern struct State data_ov002_0211022c;
extern struct State data_ov002_0211013c;
int _ZN6Player12Unk_020ca150Eh(void *c, unsigned char a){
  if(_ZN6Player7IsStateERNS_5StateE(c, &data_ov002_0211022c)){
    if(a==4){
      _ZN6Player11ChangeStateERNS_5StateE(c, &data_ov002_0211013c);
      return 1;
    }
    if(a==5) *(unsigned char*)((char*)c+0x6e3)=5;
  }
  return 0;
}
