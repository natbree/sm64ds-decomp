extern void func_0200cb58();
extern void func_0200cce4();

int func_020050dc(int *t)
{
    func_0200cb58(t, 0x1e);
    func_0200cce4(t);
    t[0x55] |= 0x100;
    return 1;
}
