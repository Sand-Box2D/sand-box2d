#pragma once

/**
 * @brief Base class for a screen,
 * an object that possesses all the screen area at this moment.
 * 
 * Is managed by ScreenManager. When game has to change the screen
 * (like from ScreenMain to ScreenSettings), ScreenManager does the following:
 * 1. First, we should say that there are two actions a screen can do: step & render.
 * 2. ScreenManager executes "step" on the active screen.
 * 3. If screen returns true, ScreenManager will render the same screen later.
 * 4. If false returned, ScreenManager will decide which screen should be the next
 * by querying the closing screen (like ScreenMain tells us to open ScreenSettings).
 * 5. Then, it will rerun the check which window should execute "step".
 * 6. After doing so it will eventually render the new screen.
 * 
 * Notice how SManager didn't render screen when it returned false.
 * We can do a little schema (0Step is one screen, 1Step is another):
 * 
 * 0Step (true) -> 0Render -> 0Step (false) -> 1Step (true) -> 1Render -> 1Step (true)...
 */

enum Screen
{
    SCREEN_MAIN = 0
};

class BaseScreen
{
public:
    virtual ~BaseScreen() {};
private:
    /* data */
};
