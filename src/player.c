#include "player.h"

void updatePlayerStub(BITMAP *backbuffer)
{
    if (IsKeyDown(KEY_ENTER))
    {
        textprintf_ex(backbuffer, font, 30, 30, makecol(255, 255, 255), 0, "Player stub: pressed enter");
    }
}