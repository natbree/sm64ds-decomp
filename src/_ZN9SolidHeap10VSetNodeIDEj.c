/* SolidHeap::VSetNodeID(u32 id) at 0x0203c3f0 -- Heap vtable slot (VSetNodeID).
 * SolidHeap has no need for node IDs (linear allocator), so this override
 * ignores the requested id and returns 0 (the previous node ID). */

typedef unsigned int u32;

struct SolidHeap;

u32 _ZN9SolidHeap10VSetNodeIDEj(struct SolidHeap *self, u32 id)
{
    return 0;
}
