//cpp
extern "C" void func_02021b98(void *base);
extern "C" void func_0203cbc0(void *p);
extern "C" void _ZN6Memory10DeallocateEPv(void *p);
extern void *data_0209ee80;
extern char data_02075f14[];
extern void *data_0209ee74;

extern "C" void *_ZN8Particle10SysTrackerD1Ev(char *thiz)
{
    if (data_0209ee80 != 0) {
        func_02021b98(thiz + 8);
        func_0203cbc0(data_0209ee80);
        data_0209ee80 = 0;
    }
    if (*(void **)thiz != (void *)data_02075f14) {
        _ZN6Memory10DeallocateEPv(*(void **)thiz);
    }
    data_0209ee74 = 0;
    return thiz;
}
