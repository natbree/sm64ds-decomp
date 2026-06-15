/* FaderBrightness::SetToStart() at 0x02017610
 * Snaps the fade to its start by setting currInterp (Fader, 0x4) to 0
 * (0.0 in 20.12 fixed point).
 */

typedef int Fix12i;

struct FaderBrightness {
    void *vtable;       /* 0x00 */
    Fix12i currInterp;  /* 0x04 (from Fader) -- fade level, 0..0x1000 */
    Fix12i speed;       /* 0x08 (from Fader) */
};

void _ZN15FaderBrightness10SetToStartEv(struct FaderBrightness *self)
{
    self->currInterp = 0;
}
