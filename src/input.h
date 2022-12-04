#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <string.h>

#include <allegro.h>

// Check if a key is being pressed
inline static bool IsKeyDown(int theKey)
{
    if (key[theKey])
    {
        return true;
    }
    return false;
}

// Check if a key has been pressed once
inline static bool IsKeyPressedOnce(int theKey)
{
    static int lastKeyState = 128;

    if (lastKeyState == theKey)
    {
        if (key[theKey])
        {
            // key is still pressed
            return false;
        }
        else
        {
            // key was just released
            lastKeyState = 128;
            return false;
        }
    }
    else
    {
        if (key[theKey])
        {
            // key was just pressed
            lastKeyState = theKey;
            return true;
        }
        else
        {
            // key is still released
            lastKeyState = 128;
            return false;
        }
    }
}
#endif