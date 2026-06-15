/* Player::OpenBigDoor() at 0x020ca144 (ov002).
 * Sets a u8 flag at offset 0x70b (1803) in the Player object to 1.
 * Player.h has only `u8 unk70b` here, so keep the typed offset access.
 */

typedef unsigned char u8;

struct Player;

void _ZN6Player11OpenBigDoorEv(struct Player *self)
{
    ((u8 *)self)[1803] = 1; /* +0x70b */
}
