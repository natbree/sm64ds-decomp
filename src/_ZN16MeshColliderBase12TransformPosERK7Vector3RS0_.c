/* MeshColliderBase::TransformPos(const Vector3& pos, Vector3& res) at 0x02039430
 * Base implementation: a non-moving mesh collider applies no transform, so it
 * leaves res untouched and returns false. (MovingMeshCollider overrides it.)
 */

typedef int Fix12i;

struct Vector3 { Fix12i x, y, z; };
struct MeshColliderBase;

int _ZN16MeshColliderBase12TransformPosERK7Vector3RS0_(struct MeshColliderBase* self, const struct Vector3* pos, struct Vector3* res)
{
    (void)self; (void)pos; (void)res;
    return 0; // false: no transform applied
}
