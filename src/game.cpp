#include "game.hpp"
#include "dbg.h"
#include "input.hpp"

#include "entity.hpp"
#include "playerPaddle/playerPaddle.hpp"

#include "scenes/splashScene.hpp"

#include <stdbool.h>

static BITMAP *ldp_BackBuffer;

volatile unsigned long gameTimeInMiliSeconds = 0;

unsigned long frameCounter = 0;
int FPS = 0;

static int set_video_mode(void);

void gameTimer(void)
{
    gameTimeInMiliSeconds += 1;
}
END_OF_FUNCTION(gameTimer);

void frameRateTimer(void)
{
    FPS = frameCounter;
    frameCounter = 0;
}
END_OF_FUNCTION(frameRateTimer);

int GameEngine::InitGame(void)
{
    if (allegro_init() != 0)
    {
        log_err("unable to initialize allegro");
        return -1;
    }

    if (install_timer() != 0)
    {
        log_err("unable to initialize allegro timer");
        return -1;
    }

    if (set_video_mode() != 0)
    {
        log_err("unable to set any graphic mode\n%s\n", allegro_error);
        return -1;
    }

    if (install_keyboard() != 0)
    {
        log_err("unable to install keyboard driver");
        return -1;
    }

    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
        log_err("unable to initialize sound driver");
        return -1;
    }

    LOCK_VARIABLE(gameTimeInMiliSeconds);
    LOCK_FUNCTION(gameTimer);
    if (install_int_ex(gameTimer, MSEC_TO_TIMER(1)) != 0)
    {
        log_err("unable to initialize game timer");
        return -1;
    }

    LOCK_VARIABLE(FPS);
    LOCK_VARIABLE(frameCounter);
    LOCK_FUNCTION(frameRateTimer);
    if (install_int_ex(frameRateTimer, SECS_TO_TIMER(1)) != 0)
    {
        log_err("unable to initialize frame rate timer");
        return -1;
    }

    // create the scene manager
    sceneManager = new SceneManager();

    // create the splash scene
    SplashScene *splashScene = new SplashScene();

    // pass scene manager ptr to splash scene
    splashScene->Init(sceneManager);

    // set scene to splash scene
    sceneManager->ChangeScene(splashScene);

    return 0;
}

static int set_video_mode(void)
{
    if (set_gfx_mode(_videoMode, _displayWidth, _displayHeight, 0, 0) != 0)
    {
        if (set_gfx_mode(GFX_SAFE, _displayWidth, _displayHeight, 0, 0) != 0)
        {
            set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
            return -1;
        }
    }

    ldp_BackBuffer = create_bitmap(vScreenHeight, vScreenWidth);
    if (ldp_BackBuffer == NULL)
    {
        log_err("unable to create backbuffer");
        return -1;
    }

    // create title screen object
    // create scene manager object
    // pass scene manager ptr to
    // set starting scene

    return 0;
}

void GameEngine::RunGame(void)
{
    bool gameIsRunning = true;
    unsigned long prevFrameTick;
    unsigned long currFrameTick = gameTimeInMiliSeconds;

    // test entities
    // PlayerPaddle thePlayer;
    // thePlayer.Init();
    // thePlayer.Update();
    // thePlayer.Destroy();

    while (gameIsRunning)
    {
        frameCounter += 1;
        prevFrameTick = currFrameTick;
        currFrameTick = gameTimeInMiliSeconds;
        double deltaTime = (currFrameTick - prevFrameTick) / 1000.0f;

        if (IsKeyPressedOnce(KEY_ESC))
        {
            gameIsRunning = false;
        }

        clear_bitmap(ldp_BackBuffer);

        textprintf_ex(ldp_BackBuffer, font, 2, 10, makecol(255, 255, 255), 0, "Frame rate: %d", FPS);
        textprintf_ex(ldp_BackBuffer, font, 2, 20, makecol(255, 255, 255), 0, "deltaTime: %lf", deltaTime);

        // update scene
        sceneManager->ProcessInput();
        sceneManager->UpdateScene(deltaTime);
        sceneManager->DrawScene(ldp_BackBuffer);

        // flip back buffer
        stretch_blit(ldp_BackBuffer, screen, 0, 0, vScreenHeight, vScreenWidth, 0, 0, _displayWidth, _displayHeight);

        rest(3); // give some time back to CPU
    }
    return;
}

void GameEngine::QuitGame(void)
{
    if (ldp_BackBuffer != NULL)
    {
        free(ldp_BackBuffer);
        ldp_BackBuffer = NULL;
    }

    return;
}