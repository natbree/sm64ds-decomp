extern int _ZN5Model8LoadFileER13SharedFilePtr(void *f);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(void *p, int file, int a, int b);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void *p);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void *p);
extern int _ZN12MeshCollider8LoadFileER13SharedFilePtr(void *f);
extern void _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(void *p, int kcl, void *mtx, int fix, short s, void *clps);
extern void func_020393d4(void *p, int v);
extern int data_ov047_021125e8[];
extern int data_ov047_021125e0[];
extern int data_ov043_02111c00[];
extern int _ZN16MeshColliderBase21UpdatePosWithVelocityERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_[];
int func_ov043_02111320(char *c){
  int f = _ZN5Model8LoadFileER13SharedFilePtr(data_ov047_021125e8);
  _ZN9ModelBase7SetFileEP8BMD_Fileii(c+0xd4, f, 1, -1);
  _ZN8Platform21UpdateModelPosAndRotYEv(c);
  _ZN8Platform19UpdateClsnPosAndRotEv(c);
  f = _ZN12MeshCollider8LoadFileER13SharedFilePtr(data_ov047_021125e0);
  _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(
    c+0x124, f, c+0x2ec, 0x199, *(short*)(c+0x8e), data_ov043_02111c00);
  func_020393d4(c+0x124, (int)_ZN16MeshColliderBase21UpdatePosWithVelocityERS_P5ActorR10ClsnResultR7Vector3P10Vector3_16S8_);
  *(short*)(c+0x94) = *(short*)(c+0x8e);
  *(int*)(c+0x98) = 0xa000;
  *(unsigned char*)(c+0x31e) = 0x3c;
  return 1;
}
