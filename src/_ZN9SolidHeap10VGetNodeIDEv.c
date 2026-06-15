/* SolidHeap::VGetNodeID() at 0x0203c3d8 -- Heap vtable slot (VGetNodeID).
 * SolidHeap has no need for node IDs (linear allocator, no per-node tagging),
 * so this override simply returns 0. */

typedef unsigned int u32;

struct SolidHeap;

u32 _ZN9SolidHeap10VGetNodeIDEv(struct SolidHeap *self)
{
    return 0;
}
