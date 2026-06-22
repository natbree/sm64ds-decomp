extern void func_02035514(char *c);
extern int *func_0203819c(int *t);
extern void func_0203ac70(int *p);
extern void _ZN10ClsnResultC1Ev(void *p);

extern int data_02099338;
extern int data_02099348;
extern int data_02099358;

void *_ZN10SphereClsnC1Ev(char *this)
{
    func_02035514(this);
    func_0203819c((int *)(this + 0x10));
    func_0203ac70((int *)(this + 0x38));
    *(int **)this = &data_02099338;
    *(int **)(this + 0x10) = &data_02099348;
    *(int **)(this + 0x38) = &data_02099358;
    _ZN10ClsnResultC1Ev(this + 0x74);
    _ZN10ClsnResultC1Ev(this + 0x9c);
    _ZN10ClsnResultC1Ev(this + 0xc4);
    *(int *)(this + 0xec) = 0;
    return this;
}
