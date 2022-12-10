#pragma once

#include "ldp_entity.h"

#include <allegro.h>

int player1_Init(struct Entity *self);
void player1_Update(struct Entity *self, double deltaTime);
void player1_Draw(struct Entity *self, BITMAP *backbuffer);