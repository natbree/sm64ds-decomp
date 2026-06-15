//cpp
extern "C" {
void _ZN9Animation12SetAnimationEti5Fix12IiEt(void* c,unsigned short a,int i,int fix,unsigned short b){
  *(int*)((char*)c+4)=i|(a<<12);
  *(int*)((char*)c+8)=b<<12;
  *(int*)((char*)c+0xc)=fix;
}
}
