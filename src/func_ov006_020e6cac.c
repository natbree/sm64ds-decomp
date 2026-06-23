void _ZN2GX15SetBankForSubBGEt(unsigned int);
void _ZN2GX16SetBankForSubOBJEt(unsigned int);
void func_ov006_020e740c(void);
void func_ov004_020aeed8(void *this);
void func_ov006_020e7508(void);
void func_ov006_020e759c(void);
extern unsigned char data_0209e660;
extern unsigned char data_0209f5f8;

void func_ov006_020e6cac(char *this) {
    _ZN2GX15SetBankForSubBGEt(*(int*)(this + 0xa0));
    _ZN2GX16SetBankForSubOBJEt(*(int*)(this + 0x4660));
    data_0209e660 = 1;
    func_ov006_020e740c();
    func_ov004_020aeed8(this);
    if (*(unsigned short*)(this + 0x4664) == 1) {
        func_ov006_020e7508();
    } else {
        func_ov006_020e759c();
        if (data_0209f5f8 == 0) data_0209f5f8 = 1;
    }
}
