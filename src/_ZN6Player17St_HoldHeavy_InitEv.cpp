//cpp
struct Vector3 { int x,y,z; };
extern "C" {
extern int data_ov002_020ff254[];
extern int _ZN6Player7SetAnimEji5Fix12IiEj(void*,unsigned int,int,int,unsigned int);
extern int _ZN5Sound13PlayCharVoiceEjjRK7Vector3(unsigned int,unsigned int,struct Vector3*);
int _ZN6Player17St_HoldHeavy_InitEv(char* c){
  *(char*)(c+0x6e5)=0;
  _ZN6Player7SetAnimEji5Fix12IiEj(c, data_ov002_020ff254[*(unsigned char*)(c+0x6e5)], 0x40000000, 0x1000, 0);
  _ZN5Sound13PlayCharVoiceEjjRK7Vector3(*(unsigned char*)(c+0x6d9), 0x12, (struct Vector3*)(c+0x74));
  return 1;
}
}
