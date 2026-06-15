/* SolidHeap::VIntact() at 0x0203c654 -- Heap vtable slot (VIntact).
 * Returns true to report the heap as a valid object. (VIntact is not a reliable
 * way to detect a broken heap; this override unconditionally returns 1.) */

typedef int bool;

struct SolidHeap;

bool _ZN9SolidHeap7VIntactEv(struct SolidHeap *self)
{
    return 1;
}
