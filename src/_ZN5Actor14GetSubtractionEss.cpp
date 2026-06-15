//cpp
extern "C" {
int _ZN5Actor14GetSubtractionEss(void*self,short a,short b){
int d=(short)(b-a);
if(d==-0x8000) d=-0x7fff;
if(d<0) d=(short)(-d);
return d;
}
}
