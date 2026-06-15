/* Camera::OnPendingDestroy() at 0x0200da00 -- vtable slot 12.
 * No-op override; the camera does nothing extra when flagged for destruction.
 */

struct Camera;

void _ZN6Camera16OnPendingDestroyEv(struct Camera *self)
{
    (void)self;
}
