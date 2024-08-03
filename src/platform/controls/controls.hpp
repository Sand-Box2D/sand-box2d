#pragma once

/**
 * @brief Controls class provides you the state of the pressed "buttons" in game.
 * 
 * Buttons and their handling is hardly linked. Button remapping is a to-do.
 * 
 * Such buttons as "close this menu" are returning the boolean (binary out),
 * While some other actions as "zoom in" might actually return a float between
 * 0 and 1. This is due to the fact that these buttons could be clicked with a 
 * different force on certain platforms.
 * 
 * It is generally suggested to have two "Controls" objects:
 * one showing the state of controls in this frame and another in the previous.
 * Like this, it's very easy to handle keyups/keydowns `(now && !old)`.
 */

class Controls
{
public:
    Controls();
    ~Controls();
private:
    /* data */
};
