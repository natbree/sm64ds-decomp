//cpp
extern "C" int _ZN6Player7IsStateERNS_5StateE(char*, void*);
extern int data_ov002_0211010c[];
extern int data_ov002_02110124[];
extern "C" int GiveHealth(int,int);
extern "C" int _ZN6Player4HealEi(char* c, int amt){
  int r = _ZN6Player7IsStateERNS_5StateE(c, data_ov002_0211010c);
  if(r) return r;
  r = _ZN6Player7IsStateERNS_5StateE(c, data_ov002_02110124);
  if(r) return r;
  return GiveHealth(*(unsigned char*)(c+0x6d8), amt);
}
