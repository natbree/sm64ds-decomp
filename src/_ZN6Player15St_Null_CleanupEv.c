/* Player::St_Null_Cleanup() at 0x020cac20 (ov002).
 * Cleanup hook of the ST_NULL do-nothing player state; returns VS_FAIL (1).
 * The implicit Player* this is unused.
 */

typedef int s32;

struct Player;

s32 _ZN6Player15St_Null_CleanupEv(struct Player *self)
{
    (void)self;
    return 1;
}
