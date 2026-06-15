/* WithMeshClsn::GetLimMovFlag() const at 0x02035694
 * Reads the LIMITED_MOVEMENT flag (1 << 7 == 0x80) of this->flags (u32 at 0x10).
 */

typedef int s32;
typedef unsigned int u32;

struct WithMeshClsn { char pad[0x10]; u32 flags; };

s32 _ZNK12WithMeshClsn13GetLimMovFlagEv(const struct WithMeshClsn* self)
{
    return self->flags & 128; // flags & LIMITED_MOVEMENT
}
