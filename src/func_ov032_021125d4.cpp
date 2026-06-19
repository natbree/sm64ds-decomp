//cpp
extern "C" {
extern void* _ZN5Model8LoadFileER13SharedFilePtr(void*);
extern void _ZN9ModelBase7SetFileEP8BMD_Fileii(void*, void*, int, int);
extern void _ZN8Platform21UpdateModelPosAndRotYEv(void*);
extern void _ZN8Platform19UpdateClsnPosAndRotEv(void*);
extern void* _ZN12MeshCollider8LoadFileER13SharedFilePtr(void*);
extern void _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(void*, void*, void*, int, short, void*);
extern int _ZN5Event6GetBitEj(unsigned int);
extern int data_ov033_021124c8[];
extern int data_ov033_021124c0[];
extern int data_ov035_02111bfc[];
int func_ov032_021125d4(char *c){
  void *f = _ZN5Model8LoadFileER13SharedFilePtr((void*)data_ov033_021124c8);
  _ZN9ModelBase7SetFileEP8BMD_Fileii(c+0xd4, f, 1, -1);
  _ZN8Platform21UpdateModelPosAndRotYEv(c);
  _ZN8Platform19UpdateClsnPosAndRotEv(c);
  void *k = _ZN12MeshCollider8LoadFileER13SharedFilePtr((void*)data_ov033_021124c0);
  _ZN18MovingMeshCollider7SetFileEP8KCL_FileRK9Matrix4x35Fix12IiEsR10CLPS_Block(c+0x124, k, c+0x2ec, 0x199, *(short*)(c+0x8e), data_ov035_02111bfc);
  return _ZN5Event6GetBitEj(0xe) == 0;
}
}
