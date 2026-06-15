extern int _ZN6Player12Unk_020c9e5cEh(void *c, unsigned char a);
extern int _ZN6Player12GetTalkStateEv(void *c);
int _ZN6Player21IsOpeningDoorWithStarEv(void *c){
  return _ZN6Player12Unk_020c9e5cEh(c,0xe) || _ZN6Player12GetTalkStateEv(c) > 0;
}
