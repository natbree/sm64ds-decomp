//cpp
extern "C" {
int _ZN5Actor24BumpedUnderneathByPlayerER6Player(char*self,char*player){
if(*(unsigned char*)(player+0x6de)!=0 && *(int*)(player+0xa8)>0
   && *(int*)(player+0x60) < *(int*)(self+0x60))
  return 1;
return 0;
}
}
