#pragma once

/**
 * @brief Renderer class implements basic functions of a renderer environment.
 * 
 * It initializes the window and its renderer, lets you get/set resolution and,
 * most importantly, provides you with the basic rendering functions
 * such as "render this texture there with this angle".
 * 
 * It could be implemented differently on different platforms.
 * For now, only SDL2 renderer is implemented.
 */

class Renderer
{
public:
    Renderer();
    ~Renderer();
private:
    /* data */
};
