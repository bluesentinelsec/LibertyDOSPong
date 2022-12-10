#pragma once

#include <allegro.h>

enum EntityState
{
    alive,
    dead
};

// allowed entity types
#define LDP_PLAYER_1_TYPE 0
#define LDP_PLAYER_2_TYPE 1
#define LDP_CPU_TYPE 2

// forward declare to appease the compiler
struct Entity;

typedef int (*ldp_InitEntity)(struct Entity *self);
typedef void (*ldp_UpdateEntity)(struct Entity *self, double deltaTime);
typedef void (*ldp_DrawEntity)(struct Entity *self, BITMAP *backbuffer);

typedef struct Entity
{
    struct Entity *self;
    int entityType;
    int entityState;
    BITMAP *bitmap;
    double speed;
    double xPos;
    double yPos;
    ldp_InitEntity InitEntity;
    ldp_UpdateEntity UpdateEntity;
    ldp_DrawEntity DrawEntity;

} Entity_t;

Entity_t *ldp_NewEntity(int entityType);
void ldp_DeleteEntity(Entity_t *);