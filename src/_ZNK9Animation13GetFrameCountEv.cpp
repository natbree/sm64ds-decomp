//cpp
extern "C" {
unsigned int _ZNK9Animation13GetFrameCountEv(void* c){
  unsigned int v=*(unsigned int*)((char*)c+4);
  return ((v&0x3fffffff)<<4)>>16;
}
}
