#include <stdlib.h>

#include <allegro.h>

#include "dbg.h"
#include "ldp_game.h"

int main(int argc, char *argv[])
{

    if (ldp_InitGame() != 0)
    {
        log_err("unable to initialize game");
        return EXIT_FAILURE;
    }

    ldp_RunGame();

    ldp_QuitGame();

    return EXIT_SUCCESS;
}
END_OF_MAIN()