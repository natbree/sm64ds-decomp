/* ActorBase::AfterBehavior(u32 vfSuccess) at 0x02043af8 -- vtable slot 8.
 * Post-behavior hook; vfSuccess is the VirtualFuncSuccess code from Behavior().
 * Base ActorBase does nothing; leaf classes override.
 */

typedef unsigned int u32;

struct ActorBase;

void _ZN9ActorBase13AfterBehaviorEj(struct ActorBase* self, u32 vfSuccess)
{
}
