#include <stdlib.h>

#include <allegro.h>

#include "dbg.h"
#include "game.hpp"

int main(int argc, char *argv[])
{

    GameEngine game;
    
    if (game.InitGame() != 0)
    {
        log_err("unable to initialize game");
        return EXIT_FAILURE;
    }

    game.RunGame();

    game.QuitGame();

    return EXIT_SUCCESS;
}
END_OF_MAIN()