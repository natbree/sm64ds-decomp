//cpp
extern "C" {
int _ZN9Animation8FinishedEv(void* c){
  unsigned int f=*(unsigned int*)((char*)c+4);
  int cur=*(int*)((char*)c+8);
  return cur>=(int)((f&0x3fffffff)-1);
}
}
