extern int func_ov006_02111dcc(char *p, int val);
extern void func_ov006_02111e48(char *o);
extern void func_0203d6d0(int *o, int *a, int *b);
extern int func_0203d614(int *v);
extern int func_ov006_02114590(char *a0, int *p, int *q0, int *q1, int *q2);
extern int func_0203d434(int *in);
extern void func_0203d630(int *p, int m);
extern void func_ov006_021128fc(char *o);
extern void func_ov006_02112ad8(char *o);
extern void func_0203d480(int *out, int *in);
extern int func_0203d524(int *a, int *b);

#define RMW(p, o) (*(int *)(((int)(p) + (o)) & 0xFFFFFFFFFFFFFFFF))

void func_ov006_02113f1c(char *self)
{
    int ca[2];
    int cb[2];
    int dv[2];
    int p1[2];
    int a1[2];
    int b1[2];
    int c1[2];
    int p2[2];
    int a2[2];
    int b2[2];
    int c2[2];
    int nrm[2];
    int dv2[2];
    int cur;
    int spd;

    if (*(int *)(self + 0x124) > 0)
        RMW(self, 0x124)--;

    if (*(unsigned char *)(self + 0x30) == 0)
        return;

    if (*(int *)(self + 0x40) > 0) {
        RMW(self, 0x40)--;
        if (*(int *)(self + 0x40) <= 0) {
            *(unsigned char *)(self + 0x30) = 0;
            return;
        }
    }

    if (*(unsigned char *)(self + 0x110) == 1) {
        *(int *)(self + 0x8) = *(int *)(self + 0x108);
        *(int *)(self + 0xc) = *(int *)(self + 0x10c);
        *(int *)(self + 0x20) = 0;
        *(int *)(self + 0x24) = 0;
        return;
    }

    if (*(int *)(self + 0x8) >= 0x8000 && *(int *)(self + 0x8) < 0xd8000
        && *(int *)(self + 0xc) >= 0x74000 && *(int *)(self + 0xc) < 0x7c000) {
        if (*(int *)(self + 0x3c) < 30) {
            RMW(self, 0x3c)++;
        } else if (*(int *)(self + 0x3c) < 300) {
            *(unsigned char *)(self + 0x3b) = 1;
            RMW(self, 0x3c)++;
        } else {
            *(unsigned char *)(self + 0x3b) = 1;
            if (func_ov006_02111dcc(self, 1)) {
                func_ov006_02111e48(self);
                return;
            }
        }
    } else {
        *(int *)(self + 0x3c) = 0;
    }

    if (*(int *)(self + 0x2c) == *(int *)(*(char **)(self + 4) + 0x4664)) {
        if (*(unsigned char *)(self + 0x121) != 0)
            *(unsigned char *)(self + 0x100) = 0;
    }

    *(int *)(self + 0x10) = *(int *)(self + 0x8);
    *(int *)(self + 0x14) = *(int *)(self + 0xc);

    if (*(int *)(self + 0x8) < 0 || *(int *)(self + 0x8) >= 0x100000
        || *(int *)(self + 0xc) < -0xf0000 || *(int *)(self + 0xc) >= 0xc0000) {
        RMW(self, 0x11c)++;
    } else {
        if ((*(int *)(*(char **)(self + 4) + 8) & 0xff) != 0) {
            int b;
            func_0203d6d0(dv, (int *)(self + 0x8), (int *)(self + 0x114));
            b = func_0203d614(dv) < 0x8000;
            if (b) {
                RMW(self, 0x11c)++;
                goto after_track;
            }
        }
        *(int *)(self + 0x11c) = 0;
        *(int *)(self + 0x114) = *(int *)(self + 0x8);
        *(int *)(self + 0x118) = *(int *)(self + 0xc);
    }
after_track:

    if (*(int *)(self + 0xfc) > 0)
        RMW(self, 0xfc)--;

    if (*(int *)(self + 0x34) > 0)
        RMW(self, 0x34)--;

    if (*(unsigned char *)(self + 0x3a) != 1 && *(unsigned char *)(self + 0x38) == 0
        && *(int *)(self + 0x8) >= 0xe8000 && *(int *)(self + 0x8) < 0xf0000
        && *(int *)(self + 0xc) >= 0x78000 && *(int *)(self + 0xc) < 0xa8000
        && *(int *)(self + 0x34) <= 0) {
        *(unsigned char *)(self + 0x38) = 1;
        *(unsigned char *)(self + 0x39) = 0;
        *(unsigned char *)(self + 0x3a) = 0;
    }

    if (*(unsigned char *)(self + 0x3a) == 0) {
        p1[0] = *(int *)(self + 0x8);
        p1[1] = *(int *)(self + 0xc);
        a1[0] = 0x8000;
        a1[1] = 0x8c000;
        b1[0] = 0x8000;
        b1[1] = 0x92000;
        c1[0] = 0xe0000;
        c1[1] = 0x96000;
        if (func_ov006_02114590(self, p1, a1, b1, c1) != 0)
            goto grow;
        p2[0] = *(int *)(self + 0x8);
        p2[1] = *(int *)(self + 0xc);
        a2[0] = 0x8000;
        a2[1] = 0x92000;
        b2[0] = 0xe0000;
        b2[1] = 0x96000;
        c2[0] = 0xe0000;
        c2[1] = 0x9e000;
        if (func_ov006_02114590(self, p2, a2, b2, c2) == 0)
            goto slow;
grow:
        RMW(self, 0x20) += 0x80;
        if (*(int *)(self + 0x20) >= 0x2000)
            *(int *)(self + 0x20) = 0x2000;
        RMW(self, 0x24) += 0x80;
        goto steer_done;
slow:
        RMW(self, 0x24) += 0x100;
steer_done:;
    }

    if (*(int *)(self + 0x20) != 0 || *(int *)(self + 0x24) != 0) {
        spd = func_0203d614((int *)(self + 0x20));
        if (spd >= 0x8000)
            spd = 0x8000;
        if (func_0203d434((int *)(self + 0x20)) != 0)
            func_0203d630((int *)(self + 0x20), spd);
    }

    RMW(self, 0x8) += *(int *)(self + 0x20);
    RMW(self, 0xc) += *(int *)(self + 0x24);

    if (*(unsigned char *)(self + 0x100) == 1) {
        func_ov006_021128fc(self);
    } else {
        func_ov006_02112ad8(self);
        if (*(unsigned char *)(self + 0x129) == 0) {
            ca[0] = 0x20000;
            ca[1] = -0x8000;
            func_0203d480(nrm, ca);
            {
                int zz = *(int *)(self + 0xc) + 0x80000;
                int xx = *(int *)(self + 0x8) - 0xd8000;
                cb[0] = xx;
                cb[1] = zz;
            }
            if (func_0203d524(ca, cb) < -*(int *)(self + 0x28))
                *(unsigned char *)(self + 0x129) = 1;
        }
    }

    cur = func_0203d614((int *)(self + 0x20));
    func_0203d6d0(dv2, (int *)(self + 0x8), (int *)(self + 0x10));
    spd = func_0203d614(dv2);
    if (*(unsigned char *)(self + 0xcd) != 0)
        return;
    if (cur < spd)
        return;
    if (cur < 0x800)
        return;
    if (func_0203d434((int *)(self + 0x20)) == 0)
        return;
    func_0203d630((int *)(self + 0x20), spd);
}
