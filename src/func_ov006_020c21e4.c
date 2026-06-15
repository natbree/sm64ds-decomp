extern int _ZN13SharedFilePtr7ReleaseEv();
extern int _ZN14BlendModelAnimD1Ev();
extern int func_02017984();
extern int func_02017ab4();

int func_ov006_020c21e4(char *t)
{
    _ZN13SharedFilePtr7ReleaseEv(t);
    _ZN13SharedFilePtr7ReleaseEv(t + 8);
    _ZN14BlendModelAnimD1Ev(t + 0x10);
    func_02017984(t + 8);
    func_02017ab4(t);
    return (int)t;
}
