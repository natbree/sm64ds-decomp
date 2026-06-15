/* MeshColliderBase::DetectClsn(SphereClsn& sphere) at 0x02039470
 * Base implementation: detects nothing and returns false. Subclasses with an
 * actual collision mesh (MeshCollider, ...) override this.
 */

struct MeshColliderBase;
struct SphereClsn;

int _ZN16MeshColliderBase10DetectClsnER10SphereClsn(struct MeshColliderBase* self, struct SphereClsn* sphere)
{
    (void)self; (void)sphere;
    return 0; // false: no collision
}
