/* ActorBase::CleanupResources() at 0x02043bf0 -- vtable slot 3.
 * Release files/heap on death. Base returns VS_FAIL (1); leaf classes override.
 */

typedef int s32;

struct ActorBase;

s32 _ZN9ActorBase16CleanupResourcesEv(struct ActorBase* self)
{
    return 1; /* VS_FAIL */
}
