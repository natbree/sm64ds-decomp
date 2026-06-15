//cpp
extern "C" unsigned int _ZNK6Player14GetBodyModelIDEjb(char*,unsigned int,char);
extern "C" int _ZN9Animation8FinishedEv(char*);
extern "C" int _ZN6Player12FinishedAnimEv(char* c){
  unsigned int id = _ZNK6Player14GetBodyModelIDEjb(c, *(int*)(c+8)&0xff, 0);
  char* m = *(char**)(c + id*4 + 0xdc);
  return _ZN9Animation8FinishedEv(m+0x50) != 0;
}
