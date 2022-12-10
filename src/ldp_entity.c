#include "ldp_entity.h"
#include "dbg.h"
#include "ldp_player1.h"

#include <stdlib.h>

Entity_t *ldp_NewEntity(int entityType)
{
    log_info("creating new entity of type: %d", entityType);
    Entity_t *theEntity = (Entity_t *)malloc(sizeof(Entity_t));
    theEntity->self = theEntity;

    if (entityType == LDP_PLAYER_1_TYPE)
    {
        theEntity->InitEntity = player1_Init;
        theEntity->UpdateEntity = player1_Update;
        theEntity->DrawEntity = player1_Draw;
    }
    else if (entityType == LDP_PLAYER_2_TYPE)
    {
        /* code */
    }
    else if (entityType == LDP_CPU_TYPE)
    {
        /* code */
    }
    else
    {
    }

    return theEntity;
}

void ldp_DeleteEntity(Entity_t *theEntity)
{
    log_info("deleting entity");
    if (theEntity->bitmap != NULL)
    {
        free(theEntity->bitmap);
        theEntity->bitmap = NULL;
    }

    if (theEntity != NULL)
    {
        free(theEntity);
        theEntity = NULL;
    }
}