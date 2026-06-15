/* MeshColliderBase::DetectClsn(RaycastGround& ray) at 0x02039480
 * Base implementation: detects nothing and returns false. Subclasses with an
 * actual collision mesh (MeshCollider, ...) override this.
 */

struct MeshColliderBase;
struct RaycastGround;

int _ZN16MeshColliderBase10DetectClsnER13RaycastGround(struct MeshColliderBase* self, struct RaycastGround* ray)
{
    (void)self; (void)ray;
    return 0; // false: no collision
}
