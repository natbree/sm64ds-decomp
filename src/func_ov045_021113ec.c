extern int _ZN5Model8LoadFileER13SharedFilePtr(void *f);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(void *p, int file, int a, int b);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void *p);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void *p);
extern int _ZN12MeshCollider8LoadFileER13SharedFilePtr(void *f);
extern void _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(void *p, int kcl, void *mtx, int fix, short s, void *clps);
extern void func_020393d4(void *p, int v);
extern void func_020393c4(void *p, int v);
extern int data_ov045_02113188[];
extern int data_ov045_02113180[];
extern int data_ov045_021125d0[];
extern int data_ov059_021114c8[];
extern int _ZN16MeshColliderBase22UpdatePosWithTransformERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_[];
int func_ov045_021113ec(char *c){
  int f = _ZN5Model8LoadFileER13SharedFilePtr(data_ov045_02113188);
  _ZN9ModelBase7SetFileEP8BMD_Fileii(c+0xd4, f, 1, -1);
  _ZN8Platform21UpdateModelPosAndRotYEv(c);
  _ZN8Platform19UpdateClsnPosAndRotEv(c);
  f = _ZN12MeshCollider8LoadFileER13SharedFilePtr(data_ov045_02113180);
  _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(
    c+0x124, f, c+0x2ec, 0x199, *(short*)(c+0x8e), data_ov045_021125d0);
  func_020393d4(c+0x124, (int)_ZN16MeshColliderBase22UpdatePosWithTransformERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_);
  func_020393c4(c+0x124, (int)data_ov059_021114c8);
  *(short*)(c+0x300+0x24) = 0;
  *(unsigned char*)(c+0x327) = 0;
  *(int*)(c+0x320) = *(int*)(c+0x60);
  return 1;
}
