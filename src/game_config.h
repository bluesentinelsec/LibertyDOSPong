#pragma once

#include <allegro.h>

static int virtual_screen_width = 320;
static int virtual_screen_height = 200;

#ifdef __DJGPP__
static int video_mode = GFX_AUTODETECT;
static int display_width = 320;
static int display_height = 200;
#elif __GNUC__
static int video_mode = GFX_AUTODETECT_WINDOWED;
static int display_width = 1024;
static int display_height = 768;
#endif

