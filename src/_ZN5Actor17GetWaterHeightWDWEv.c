extern signed char data_0209f2f8[];
extern unsigned char data_0209f2c0[];
extern int data_02075244[];
int _ZN5Actor17GetWaterHeightWDWEv(char *self) {
  int ret = *(int*)(self+0x60);
  if (data_0209f2f8[0] == 0x15 && *(signed char*)(self+0xcc) == 0) {
    unsigned int i = data_0209f2c0[0];
    if (i >= 3) i = 2;
    ret = data_02075244[i];
  }
  return ret;
}
