/* Player::OnYoshiTryEat() at 0x020e69b8 (ov002) -- vtable slot 17.
 * Overrides Actor's slot 17; returns an OnYoshiEatReturnVal of 1
 * (Yoshi cannot eat the Player). The implicit Player* this is unused.
 */

typedef unsigned int u32;

struct Player;

u32 _ZN6Player13OnYoshiTryEatEv(struct Player *self)
{
    (void)self;
    return 1;
}
