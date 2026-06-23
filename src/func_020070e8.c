struct Vector3 { int x, y, z; };
extern void func_02007c9c(const struct Vector3 *v0, const struct Vector3 *v1, int *outDist, short *outVertAng, short *outHorzAng);
extern void Math_Function_0203b0fc(int *p, int target, int scale, int max);
extern int ApproachAngle(short *angle, int targetAngle, int invFactor, int maxDelta, int minDelta);
extern void func_02007c14(struct Vector3 *res, const struct Vector3 *trans, int mag, short ang, short angY);

void func_020070e8(int *thiz, int p1, int p2, int p3, short flagV, short targetH, short flagH)
{
    int dist;
    short vertAng;
    short horzAng;
    struct Vector3 *trans = (struct Vector3*)((char*)*(int**)((char*)thiz + 0x110) + 0x5c);
    func_02007c9c(trans, (struct Vector3*)((char*)thiz + 0x8c), &dist, &vertAng, &horzAng);
    Math_Function_0203b0fc(&dist, p1, p2, 0x7fffffff);
    if (flagV != 0)
        ApproachAngle(&vertAng, p3, flagV, 0x4000, 0);
    if (flagH != 0)
        ApproachAngle(&horzAng, targetH, flagH, 0x4000, 0);
    func_02007c14((struct Vector3*)((char*)thiz + 0x8c), trans, dist, vertAng, horzAng);
}
