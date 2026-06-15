/* Animation::Copy(const Animation& anim) at 0x02015a7c
 * Copies the three Fix12i members from `anim` into `self`, leaving the vtable
 * pointer (slot 0x0) untouched: numFramesAndFlags(0x4), currFrame(0x8),
 * speed(0xc).
 */

typedef int Fix12i;

struct Animation {
    void *vtable;             /* 0x00 */
    Fix12i numFramesAndFlags; /* 0x04 */
    Fix12i currFrame;         /* 0x08 */
    Fix12i speed;             /* 0x0c */
};

void _ZN9Animation4CopyERKS_(struct Animation *self, const struct Animation *anim)
{
    self->numFramesAndFlags = anim->numFramesAndFlags;
    self->currFrame         = anim->currFrame;
    self->speed             = anim->speed;
}
