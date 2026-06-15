extern unsigned char data_0209cab4[];
int IsStarCollected(int r0, int r1){
  return ((1 << r1) & data_0209cab4[r0]) & 0xff;
}
