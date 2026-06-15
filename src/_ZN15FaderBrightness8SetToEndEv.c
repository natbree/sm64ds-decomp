/* FaderBrightness::SetToEnd() at 0x0201761c
 * Snaps the fade to its end by setting currInterp (Fader, 0x4) to 4096
 * (0x1000 == 1.0 in 20.12 fixed point).
 */

typedef int Fix12i;

struct FaderBrightness {
    void *vtable;       /* 0x00 */
    Fix12i currInterp;  /* 0x04 (from Fader) -- fade level, 0..0x1000 */
    Fix12i speed;       /* 0x08 (from Fader) */
};

void _ZN15FaderBrightness8SetToEndEv(struct FaderBrightness *self)
{
    self->currInterp = 4096;
}
