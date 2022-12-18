#pragma once

#include "sceneManager.hpp"

#include <allegro.h>

class GameEngine
{
public:
    int InitGame(void);
    void RunGame(void);
    void QuitGame(void);

private:
    SceneManager *sceneManager;
};

// define the logical screen height and width
static int vScreenHeight = 320;
static int vScreenWidth = 200;

// define the physical screen width and height
// for MS-DOS platforms
#ifdef __DJGPP__
static int _videoMode = GFX_AUTODETECT;
static int _displayWidth = 320;
static int _displayHeight = 200;

#else
// define the physical screen width and height
// for non-DOS platforms
static int _videoMode = GFX_AUTODETECT_WINDOWED;
static int _displayWidth = 1024;
static int _displayHeight = 768;
#endif
