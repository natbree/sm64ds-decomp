extern int func_ov002_020caf68(void *c);
extern int data_ov002_021106dc[];
extern int data_ov002_021106f4[];
int _ZN6Player16St_Climb_CleanupEv(void *c){
  int v = *(int*)((char*)c+0x378);
  if(v != (int)data_ov002_021106dc && v != (int)data_ov002_021106f4){
    func_ov002_020caf68(c);
    *(unsigned short*)((char*)c+0x600+0xb6)=8;
  }
  *(unsigned short*)((char*)c+0x600+0xa8)=0;
  return 1;
}
