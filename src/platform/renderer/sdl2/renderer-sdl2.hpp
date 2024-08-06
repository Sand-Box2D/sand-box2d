#include "../renderer.hpp"

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

/**
 * @brief SDL2 Implementation for Renderer.
 * 
 * Implements a renderer with SDL2 window and its SDL2_renderer.
 * 
 * This way, we use SDL2 functions to render textures
 * or more graphical stuff with SDL2_gfx.
 * 
 * For the moment, it's the only renderer implementation for the game
 * (GLFW / OpenGL and Metal might appear later).
 */
class RendererSdl2 : public BaseRenderer
{
public:
    RendererSdl2();
    ~RendererSdl2();

    /// @brief Init the graphical environment (create a window and its renderer).
    /// @param rendererParams RendererParams to overwrite if needed.
    /// @return True if could init correctly. False if not.
    bool init(RendererParams rendererParams = RendererParams());

    /// @brief Set the new renderer params when need to update.
    ///
    /// It won't init the renderer. Call `init()` instead.
    /// @param rendererParams New RendererParams.
    void setParams(RendererParams rendererParams);

    /// @brief Get current width of the renderer window in pixels.
    /// Game window might be bigger though. Refer to `getScale()`.
    ///
    /// Still, you need to consider this resolution when rendering.
    /// @return 0 if didn't yet init renderer.
    int getWidth();

    /// @brief Get current height of the renderer window in pixels.
    /// Game window might be bigger though. Refer to `getScale()`.
    ///
    /// Still, you need to consider this resolution when rendering.
    /// @return 0 if didn't yet init renderer.
    int getHeight();

    /// @brief Get a value that gives the physical size of the renderer window when
    /// multiplied with the game env size (`getWidth()` and `getHeight()`).
    /// @return 0 if didn't yet init renderer.
    float getScale();

    /// @brief Get time between two renders in milliseconds.
    /// @return 0 if didn't yet init renderer.
    float getDelta();

    /// @brief Get rendered frames count since the renderer init.
    /// @return 0 if didn't yet init renderer.
    unsigned long int getFrames();

    /// @brief Fill the whole screen with a single color.
    /// @param color Desired color of the screen (background even).
    void clearScreen(RendererColor color);

    /// @brief Swap the renderer buffer and show everything that was rendered.
    void render();

private:
    /// @brief Window for the SDL2 Renderer impl.
    SDL_Window *mp_Window;

    /// @brief Renderer for this SDL2 impl.
    SDL_Renderer *mp_Renderer;
};
