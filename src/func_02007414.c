int func_02007414(void* c){
  *(int*)((char*)c+0xb0)=0;
  *(int*)((char*)c+0xb4)=0;
  *(int*)((char*)c+0xb8)=0;
  int r1=*(int*)((char*)c+0x110);
  int r2=*(int*)((char*)c+0x84);
  r1=*(int*)((char*)r1+0x60);
  *(int*)((char*)c+0xbc)=0;
  *(int*)((char*)c+0xc0)=r2-r1;
  *(int*)((char*)c+0xc4)=0;
  *(int*)((char*)c+0x170)=0;
  *(int*)((char*)c+0x174)=0;
  return 1;
}
