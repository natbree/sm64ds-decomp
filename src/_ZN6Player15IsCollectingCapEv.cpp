//cpp
extern "C" int _ZN6Player15IsCollectingCapEv(char* c){
  unsigned short v = *(unsigned short*)(c+0x73c);
  if(v!=0 && (v&7)<5) return 1;
  return 0;
}
