/* Animation::GetFlags() at 0x02015bec
 * Returns the top 2 bits (Animation::FLAG_MASK == 0xC0000000) of the
 * numFramesAndFlags word at offset 0x4 -- the loop flags (LOOP=0, NO_LOOP=0x40000000).
 */

typedef int s32;

struct Animation {
    void *vtable;          /* 0x00 */
    s32 numFramesAndFlags; /* 0x04 */
    s32 currFrame;         /* 0x08 */
    s32 speed;             /* 0x0c */
};

s32 _ZN9Animation8GetFlagsEv(struct Animation *self)
{
    return self->numFramesAndFlags & 0xC0000000;
}
