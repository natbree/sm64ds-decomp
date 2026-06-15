struct State { int a; int b; };
extern int _ZN6Player7IsStateERNS_5StateE(void *c, struct State *s);
extern struct State data_ov002_0211064c;
extern struct State data_ov002_02110664;
int _ZN6Player12Unk_020ca8f8Ev(void *c){
  if(_ZN6Player7IsStateERNS_5StateE(c, &data_ov002_0211064c)) return 1;
  if(_ZN6Player7IsStateERNS_5StateE(c, &data_ov002_02110664)) return 2;
  return 0;
}
