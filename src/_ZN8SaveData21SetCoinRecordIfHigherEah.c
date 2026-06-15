extern unsigned char data_0209cad2[];
void _ZN8SaveData21SetCoinRecordIfHigherEah(int a, unsigned char b){
  if (b > data_0209cad2[a])
    data_0209cad2[a] = b;
}
