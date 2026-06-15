/* Stage::OnPendingDestroy() at 0x0202b8a0
 * ActorBase vtable slot 12 (0x30), called when the Stage scene is marked for
 * destruction, before CleanupResources(). Stage overrides it with an empty body
 * -- no teardown work needed at this point.
 * `this` is Stage* (Stage derives from Scene <- ActorDerived <- ActorBase).
 */

struct Stage;

void _ZN5Stage16OnPendingDestroyEv(struct Stage* self)
{
    (void)self;
}
