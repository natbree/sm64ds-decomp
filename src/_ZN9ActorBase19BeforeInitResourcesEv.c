/* ActorBase::BeforeInitResources() at 0x02043c78 -- vtable slot 1, init guard.
 * Base returns the VirtualFuncSuccess code VS_FAIL (1); leaf classes override.
 */

typedef int bool;

struct ActorBase;

bool _ZN9ActorBase19BeforeInitResourcesEv(struct ActorBase* self)
{
    return 1; /* VS_FAIL */
}
