extern void func_ov006_020e3388(void*);
extern void func_ov006_020e3250(void*);
extern void _ZN3G2x13SetBlendAlphaEPVttttt(volatile void*,unsigned short,unsigned short,unsigned short,unsigned short);
extern int func_ov004_020adc1c(void);
void func_ov006_020e3470(unsigned char* c){
  *(int*)(c+0x4eac)=0;
  func_ov006_020e3388(c);
  func_ov006_020e3250(c);
  _ZN3G2x13SetBlendAlphaEPVttttt((volatile void*)0x4000050,0,0xd,2,0x10);
  _ZN3G2x13SetBlendAlphaEPVttttt((volatile void*)0x4001050,0,4,2,0x10);
  *(int*)(c+0x4ed8)=func_ov004_020adc1c();
}
