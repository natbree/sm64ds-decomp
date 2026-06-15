void func_0200c9e0(void* c, int* r1, int* r2){
  int r3=*(int*)((char*)c+0x154);
  if(r3 & 0x10000){
    *r1=0xfffffd39;
    *r2=0xfffffd39;
    return;
  }
  if(r3 & 0x20000){
    *r1=0xd1b;
    *r2=0xd1b;
  }
}
