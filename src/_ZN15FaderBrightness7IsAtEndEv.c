/* FaderBrightness::IsAtEnd() at 0x02017670
 * Returns true when currInterp (Fader, 0x4) has reached 4096
 * (0x1000 == 1.0 in 20.12 fixed point).
 */

typedef int Fix12i;

struct FaderBrightness {
    void *vtable;       /* 0x00 */
    Fix12i currInterp;  /* 0x04 (from Fader) -- fade level, 0..0x1000 */
    Fix12i speed;       /* 0x08 (from Fader) */
};

int _ZN15FaderBrightness7IsAtEndEv(struct FaderBrightness *self)
{
    return self->currInterp == 4096;
}
