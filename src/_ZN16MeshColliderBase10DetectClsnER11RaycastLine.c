/* MeshColliderBase::DetectClsn(RaycastLine& ray) at 0x02039478
 * Base implementation: detects nothing and returns false. Subclasses with an
 * actual collision mesh (MeshCollider, ...) override this.
 */

struct MeshColliderBase;
struct RaycastLine;

int _ZN16MeshColliderBase10DetectClsnER11RaycastLine(struct MeshColliderBase* self, struct RaycastLine* ray)
{
    (void)self; (void)ray;
    return 0; // false: no collision
}
