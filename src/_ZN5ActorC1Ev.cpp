//cpp
extern "C" {
void _ZN9ActorBaseC1Ev(void* self);
void func_0203b244(void* l, void* n);
void _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(void* self, int a, int b, int c, int d);
}
extern void* data_0208e4b8;
extern void* data_0208e3a4;
extern void* data_0209b468;
extern void* data_0209b460;
extern void* data_0209b45c;
extern signed char data_0209b44c;
extern short data_0208e378;
extern void* data_020a4bb8;
extern unsigned char data_0209f2d8;

extern "C" void* _ZN5ActorC1Ev(char* c) {
  _ZN9ActorBaseC1Ev(c);
  *(void**)c = &data_0208e4b8;
  *(void**)c = &data_0208e3a4;
  *(int*)(c+0x50) = 0;
  *(int*)(c+0x54) = 0;
  *(void**)(c+0x58) = c;
  func_0203b244(&data_0209b468, c+0x50);
  {
    int* p = (int*)data_0209b460;
    if (p) {
      *(int*)(c+0x5c) = p[0];
      *(int*)(c+0x60) = p[1];
      *(int*)(c+0x64) = p[2];
    }
  }
  {
    short* q = (short*)data_0209b45c;
    if (q) {
      *(short*)(c+0x8c) = q[0];
      *(short*)(c+0x8e) = q[1];
      *(short*)(c+0x90) = q[2];
      q = (short*)data_0209b45c;
      *(short*)(c+0x92) = q[0];
      *(short*)(c+0x94) = q[1];
      *(short*)(c+0x96) = q[2];
    }
  }
  *(signed char*)(c+0xcc) = data_0209b44c;
  *(short*)(c+0xce) = data_0208e378;
  {
    void** base = *(void***)&data_020a4bb8;
    int idx = *(unsigned short*)(c+0xc);
    char* s = (char*)base[idx];
    *(int*)(c+0xb0) = *(int*)(s+8);
    {
      int b = (data_0209f2d8 == 2);
      int r3;
      int d = *(int*)(s+0x18);
      if (b) r3 = *(int*)(s+0x14) + 0x7d0000;
      else r3 = *(int*)(s+0x14);
      _ZN5Actor9SetRangesE5Fix12IiES1_S1_S1_(c, *(int*)(s+0xc), *(int*)(s+0x10), r3, d);
    }
  }
  return c;
}
