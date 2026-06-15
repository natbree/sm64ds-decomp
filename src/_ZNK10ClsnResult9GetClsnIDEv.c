/* ClsnResult::GetClsnID() const at 0x02037f4c
 * Loads the u32 field at 0x1c (objID in the reference layout).
 */

typedef unsigned int u32;

struct ClsnResult;

u32 _ZNK10ClsnResult9GetClsnIDEv(const struct ClsnResult* self)
{
    return ((const u32*)self)[7]; // +0x1c
}
