#include "dbg.h"
#include "game_config.h"
#include "input.h"
#include "player.h"

#include <allegro.h>
#include <stdlib.h>

unsigned long gameTimeInMiliSeconds = 0;
const int fps = 60.0f;
const int frameDelay = 1000.0f / fps;

int frameCounter = 0;
int AvgFPS = 0;

void gameTimer(void)
{
    gameTimeInMiliSeconds += 1;
}
END_OF_FUNCTION(gameTimer);

void fpsCounter(void)
{
    AvgFPS = frameCounter;
    frameCounter = 0;
}
END_OF_FUNCTION(fpsCounter);

int main(int argc, char *argv[])
{
    // initialize allegro game library
    if (allegro_init() != 0)
    {
        log_err("unable to initialize lib Allegro");
        return EXIT_FAILURE;
    }

    // set video mode
    if (set_gfx_mode(_videoMode, _displayWidth, _displayHeight, 0, 0) != 0)
    {
        log_err("unable to set video mode");
        return EXIT_FAILURE;
    }

    // initialize allegro drivers

    if (install_timer() != 0)
    {
        log_err("unable to initialize timer");
        return EXIT_FAILURE;
    }

    if (install_keyboard() != 0)
    {
        log_err("unable to initialize keyboard");
        return EXIT_FAILURE;
    }

    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
        log_err("unable to initialize sound driver");
        return EXIT_FAILURE;
    }

    // load resources

    // load MIDI file
    MIDI *music = load_midi("media/brinstar.mid");
    if (!music)
    {
        log_err("unable to load midi file");
        return EXIT_FAILURE;
    }

    // play midi file
    if (play_midi(music, 0) != 0)
    {
        log_err("unable to play midi file");
        return EXIT_FAILURE;
    }

    // load wav
    SAMPLE *sfx = load_sample("media/jump.wav");
    if (!sfx)
    {
        log_err("unable to load wav file");
        return EXIT_FAILURE;
    }

    // play wav
    if (play_sample(sfx, 128, 128, 1000, FALSE) != 0)
    {
        log_err("unable to play wav file");
        return EXIT_FAILURE;
    }

    // setup timer
    LOCK_VARIABLE(gameTimeInMiliSeconds);
    LOCK_FUNCTION(gameTimer);
    install_int(gameTimer, 1);

    LOCK_VARIABLE(AvgFPS);
    LOCK_FUNCTION(fpsCounter);
    install_int(fpsCounter, 1000);

    // create backbuffer
    BITMAP *backbuffer = create_bitmap(vScreenHeight, vScreenWidth);
    int BLACK = makecol(0, 0, 0);
    int WHITE = makecol(255, 255, 255);
    int GREEN = makecol(0, 255, 0);

    float yPos = 50;
    float xPos = 50;

    // game loop

    int speed = 100;
    unsigned long prevFrameTick;
    unsigned long currFrameTick = gameTimeInMiliSeconds;

    while (!key[KEY_ESC])
    {
        // measure start of frame
        prevFrameTick = currFrameTick;
        currFrameTick = gameTimeInMiliSeconds;
        double deltaTime = (currFrameTick - prevFrameTick) / 1000.0f;

        frameCounter += 1;

        // clear backbuffer
        rectfill(backbuffer, 0, 0, vScreenHeight, vScreenWidth, BLACK);

        updatePlayerStub(backbuffer);

        if (key[KEY_UP])
        {
            textout_ex(backbuffer, font, "pressed up", 10, 10, WHITE, 0);
            yPos -= speed * deltaTime;
        }

        if (key[KEY_DOWN])
        {
            textout_ex(backbuffer, font, "pressed down", 10, 10, WHITE, 0);
            yPos += speed * deltaTime;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            textout_ex(backbuffer, font, "pressed left", 10, 10, WHITE, 0);
            xPos -= speed * deltaTime;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            textout_ex(backbuffer, font, "pressed right", 10, 10, WHITE, 0);
            xPos += speed * deltaTime;
        }

        if (IsKeyPressedOnce(KEY_SPACE))
        {
            textout_ex(backbuffer, font, "pressed space", 10, 10, WHITE, 0);
            yPos -= speed;
        }

        circlefill(backbuffer, xPos, yPos, 40, GREEN);

        // game loop
        textprintf_ex(backbuffer, font, 2, 20, WHITE, 0, "Total game ticks: %lu", gameTimeInMiliSeconds);
        textprintf_ex(backbuffer, font, 2, 30, WHITE, 0, "currFrameTick: %lu", currFrameTick);
        textprintf_ex(backbuffer, font, 2, 40, WHITE, 0, "prevFrameTick: %lu", prevFrameTick);
        textprintf_ex(backbuffer, font, 2, 50, WHITE, 0, "deltaTime: %lf", deltaTime);
        textprintf_ex(backbuffer, font, 2, 60, WHITE, 0, "FPS: %d", AvgFPS);
        textprintf_ex(backbuffer, font, 2, 70, WHITE, 0, "xPos: %.2f", xPos);
        textprintf_ex(backbuffer, font, 2, 80, WHITE, 0, "yPos: %.2f", yPos);

        // flip back buffer
        stretch_blit(backbuffer, screen, 0, 0, vScreenHeight, vScreenWidth, 0, 0, _displayWidth, _displayHeight);
        
        rest(5); // give some time back to CPU
    }

    destroy_midi(music);
    destroy_sample(sfx);

    return EXIT_SUCCESS;
}
END_OF_MAIN()