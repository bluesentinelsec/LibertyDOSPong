#include "dbg.h"
#include "game_config.h"
#include "input.h"
#include "player.h"

#include <allegro.h>
#include <stdlib.h>

unsigned long long int ticks = 0;
const double fps = 60.0f;
const double frameDelay = 1000.0f / fps;

int frameCounter = 0;
int AvgFPS = 0;

void gameTimer(void)
{
    ticks += 1;
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
    LOCK_VARIABLE(ticks);
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

    int yPos = 50;
    int xPos = 50;

    // game loop
    unsigned long long int startFrameTime = 0;
    unsigned long long int endFrameTime = 0;

    int speed = 10;
    while (!key[KEY_ESC])
    {
        // measure start of frame
        startFrameTime = ticks;
        frameCounter += 1;

        // clear backbuffer
        rectfill(backbuffer, 0, 0, vScreenHeight, vScreenWidth, BLACK);

        updatePlayerStub(backbuffer);

        if (key[KEY_UP])
        {
            textout_ex(backbuffer, font, "pressed up", 10, 10, WHITE, 0);
            yPos -= speed * endFrameTime;
        }

        if (key[KEY_DOWN])
        {
            textout_ex(backbuffer, font, "pressed down", 10, 10, WHITE, 0);
            yPos += speed * endFrameTime;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            textout_ex(backbuffer, font, "pressed left", 10, 10, WHITE, 0);
            xPos -= speed * endFrameTime;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            textout_ex(backbuffer, font, "pressed right", 10, 10, WHITE, 0);
            xPos += speed * endFrameTime;
        }

        if (IsKeyPressedOnce(KEY_SPACE))
        {
            textout_ex(backbuffer, font, "pressed space", 10, 10, WHITE, 0);
            yPos -= speed * endFrameTime;
        }

        // clamp circle to screen
        if (yPos >= vScreenHeight)
            yPos = vScreenHeight;
        if (yPos <= 0)
            yPos = 0;
        if (xPos >= vScreenWidth)
            xPos = vScreenWidth;
        if (xPos <= 0)
            xPos = 0;

        circlefill(backbuffer, xPos, yPos, 40, GREEN);
        textout_ex(backbuffer, font, "TEXT", 10, 20, GREEN, 0);
        textprintf_ex(backbuffer, font, 2, 100, WHITE, 0, "FPS: %d", AvgFPS);

        // game loop

        // flip back buffer
        stretch_blit(backbuffer, screen, 0, 0, vScreenHeight, vScreenWidth, 0, 0, _displayWidth, _displayHeight);

        // measure end of frame
        endFrameTime = ticks - startFrameTime;

        if (endFrameTime < frameDelay)
        {
            double rest_period = frameDelay - endFrameTime;
            rest(rest_period);
        }
    }

    destroy_midi(music);
    destroy_sample(sfx);

    return EXIT_SUCCESS;
}
END_OF_MAIN()