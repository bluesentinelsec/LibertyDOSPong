#include "ldp_player1.h"
#include "dbg.h"

int player1_Init(struct Entity *self)
{
    log_info("initializing player1");
    self->xPos = 20;
    self->yPos = 20;
}

void player1_Update(struct Entity *self, double deltaTime)
{
    log_info("updating player1");
}

void player1_Draw(struct Entity *self, BITMAP *backbuffer)
{
    log_info("drawing player1");
}