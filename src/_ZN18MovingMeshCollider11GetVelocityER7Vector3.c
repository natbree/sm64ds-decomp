/* MovingMeshCollider::GetVelocity(Vector3& out) at 0x02039908
 * Copies this->velocity (Vector3 at 0x124) into out.
 */

typedef int Fix12i;

struct Vector3 { Fix12i x, y, z; };
struct MovingMeshCollider { char pad[0x124]; struct Vector3 velocity; };

void _ZN18MovingMeshCollider11GetVelocityER7Vector3(struct MovingMeshCollider* self, struct Vector3* out)
{
    out->x = self->velocity.x;
    out->y = self->velocity.y;
    out->z = self->velocity.z;
}
