/* HUD::CleanupResources() at 0x020fd5d4 (ov002) -- vtable slot 3.
 * Returns VS_FAIL (1); the HUD holds no SharedFilePtr/heap resources to
 * release on death. HUD : ActorDerived : ActorBase.
 */

typedef int s32;

struct HUD;

s32 _ZN3HUD16CleanupResourcesEv(struct HUD *self)
{
    (void)self;
    return 1;
}
