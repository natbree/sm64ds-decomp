//cpp
extern short data_02092144[];
extern "C" int _ZN6Player9GetHealthEv(char* c){
  unsigned char i = *(unsigned char*)(c+0x6d8);
  return (signed char)(data_02092144[i] >> 8);
}
