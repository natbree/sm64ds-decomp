extern void func_ov006_020e668c(void*);
extern void func_ov006_020e6528(void*);
extern void _ZN3G2x13SetBlendAlphaEPVttttt(volatile void*,unsigned short,unsigned short,unsigned short,unsigned short);
extern int func_ov004_020adc1c(void);
void func_ov006_020e6774(unsigned char* c){
  *(int*)(c+0x5580)=0;
  func_ov006_020e668c(c);
  func_ov006_020e6528(c);
  _ZN3G2x13SetBlendAlphaEPVttttt((volatile void*)0x4000050,0,0xd,2,0x10);
  _ZN3G2x13SetBlendAlphaEPVttttt((volatile void*)0x4001050,0,4,2,0x10);
  *(int*)(c+0x55ac)=func_ov004_020adc1c();
}
