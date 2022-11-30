#include <allegro.h>
#include <stdlib.h>

#include "dbg.h"
#include "game_config.h"

int main(int argc, char *argv[])
{
    // initialize allegro game library
    if (allegro_init() != 0)
    {
        log_err("unable to initialize lib Allegro");
        return EXIT_FAILURE;
    }

    // initialize allegro drivers
    install_timer();
    install_keyboard();

    // set video mode
    if (set_gfx_mode(video_mode, display_width, display_height, 0, 0) != 0)
    {
        log_err("unable to set video mode");
        return EXIT_FAILURE;
    }

    // install sound driver
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
        log_err("unable to initialize sound driver");
        return EXIT_FAILURE;
    }

    // load MIDI file
    MIDI *music = load_midi("media/kraid.mid");
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

    // create backbuffer
    BITMAP *backbuffer = create_bitmap(virtual_screen_width, virtual_screen_height);
    int BLACK = makecol(0, 0, 0);

    // game loop
    while (!key[KEY_ESC])
    {
        // clear backbuffer
        rectfill(backbuffer, 0, 0, virtual_screen_width, virtual_screen_height, BLACK);

        // make sure we're actually drawing to the screen
        circlefill(backbuffer, virtual_screen_width / 2, virtual_screen_height / 2, 40, makecol(0, 255, 0));

        // game loop

        // flip back buffer
        stretch_blit(backbuffer, screen, 0, 0, virtual_screen_width, virtual_screen_height, 0, 0, display_width, display_height);
    }

    destroy_midi(music);

    return EXIT_SUCCESS;
}
END_OF_MAIN()