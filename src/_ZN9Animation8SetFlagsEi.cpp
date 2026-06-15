//cpp
extern "C" {
void _ZN9Animation8SetFlagsEi(void* c,int flags){
  *(unsigned int*)((char*)c+4)=(*(unsigned int*)((char*)c+4)&0x3fffffff)|flags;
}
}
