extern void func_ov004_020b0aa0(int n);
extern void func_ov006_02103bfc(char *p);
void func_ov006_02103cbc(char *c, int n){
    *(int*)(c+0x5000+0x660) = 0;
    if(n == 0x10){
        *(int*)(c+0xbc) = *(int*)(c+0xbc) + 1;
        if(*(unsigned int*)(c+0xbc) > 0x270e) *(int*)(c+0xbc) = 0x270e;
    } else {
        *(int*)(c+0xbc) = 0;
        if(*(unsigned int*)(c+0xbc) > 0x270e) *(int*)(c+0xbc) = 0x270e;
    }
    func_ov004_020b0aa0(0x1d);
    func_ov006_02103bfc(c);
}
