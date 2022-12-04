#include "player.h"

void updatePlayerStub(BITMAP *wtf)
{
    if (IsKeyPressedOnce(KEY_ENTER))
    {
        textprintf_ex(wtf, font, 30, 30, makecol(255, 255, 255), 0, "Player stub: pressed enter");
    }
}