/* CylinderClsnWithPos::GetOwnerID() at 0x02014818
 * vtable slot 3. A positional cylinder has no owning Actor, so its owner ID
 * is always 0.
 */

typedef unsigned int u32;

struct CylinderClsnWithPos;

u32 _ZN19CylinderClsnWithPos10GetOwnerIDEv(struct CylinderClsnWithPos* self)
{
    (void)self;
    return 0;
}
