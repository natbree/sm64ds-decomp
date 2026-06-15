/* Player::St_Null_Main() at 0x020cac28 (ov002).
 * Main hook of the ST_NULL do-nothing player state; returns VS_FAIL (1).
 * (All ST_NULL state functions are "return 1;" per Player.h.)
 */

typedef int s32;

struct Player;

s32 _ZN6Player12St_Null_MainEv(struct Player *self)
{
    (void)self;
    return 1;
}
