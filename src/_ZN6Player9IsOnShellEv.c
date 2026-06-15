struct State { int a; int b; };
extern int _ZN6Player7IsStateERNS_5StateE(void *c, struct State *s);
extern struct State data_ov002_02110304;
int _ZN6Player9IsOnShellEv(void *c){
  if(_ZN6Player7IsStateERNS_5StateE(c, &data_ov002_02110304)) return 1;
  *(int*)((char*)c+0x354)=0;
  return 0;
}
