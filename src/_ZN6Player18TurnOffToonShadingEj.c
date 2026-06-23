extern int _ZNK6Player14GetBodyModelIDEjb(void*, unsigned int, int);
extern int _ZN5Model14SetPolygonModeEi(void*, int);
extern int func_ov002_020e6b74(void*, int);
void _ZN6Player18TurnOffToonShadingEj(char* c, unsigned int j) {
  void* m;
  m = ((void**)(c + 0xdc))[_ZNK6Player14GetBodyModelIDEjb(c, j, 0)];
  _ZN5Model14SetPolygonModeEi(m, 0);
  func_ov002_020e6b74(m, ((int*)(c + 0x27c))[j]);
  m = ((void**)(c + 0x154))[j];
  _ZN5Model14SetPolygonModeEi(m, 0);
  func_ov002_020e6b74(m, ((int*)(c + 0x28c))[j]);
  m = ((void**)(c + 0x154))[j + 4];
  _ZN5Model14SetPolygonModeEi(m, 0);
  func_ov002_020e6b74(m, ((int*)(c + 0x28c))[j + 4]);
}
