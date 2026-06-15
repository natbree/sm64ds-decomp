//cpp
extern "C" {
struct Actor;
extern struct Actor* data_0209b468;
struct Actor* _ZN5Actor4NextEPKS_(struct Actor* c){
  struct Actor* p;
  if(c) p = *(struct Actor**)((char*)c+0x54);
  else  p = *(struct Actor**)&data_0209b468;
  if(p) return *(struct Actor**)((char*)p+8);
  return 0;
}
}
