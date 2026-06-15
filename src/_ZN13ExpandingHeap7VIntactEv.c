/* ExpandingHeap::VIntact() at 0x0203c65c -- Heap vtable slot (VIntact).
 * Returns true to report the heap as a valid object. (VIntact is not a reliable
 * way to detect a broken heap; this override unconditionally returns 1.) */

typedef int bool;

struct ExpandingHeap;

bool _ZN13ExpandingHeap7VIntactEv(struct ExpandingHeap *self)
{
    return 1;
}
