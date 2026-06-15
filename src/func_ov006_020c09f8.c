extern int _ZN13SharedFilePtr7ReleaseEv();
extern int _ZN11ShadowModelD1Ev();
extern int _ZN14BlendModelAnimD1Ev();
extern int func_02017984();
extern int func_02017ab4();

int func_ov006_020c09f8(char *t)
{
    _ZN13SharedFilePtr7ReleaseEv(t);
    _ZN13SharedFilePtr7ReleaseEv(t + 0x10);
    _ZN13SharedFilePtr7ReleaseEv(t + 8);
    _ZN11ShadowModelD1Ev(t + 0x88);
    _ZN14BlendModelAnimD1Ev(t + 0x18);
    func_02017984(t + 0x10);
    func_02017984(t + 8);
    func_02017ab4(t);
    return (int)t;
}
