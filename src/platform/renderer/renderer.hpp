#pragma once

/**
 * @brief Renderer class implements basic functions of a renderer environment.
 * 
 * It initializes the window and its renderer, lets you get/set resolution and,
 * most importantly, provides you the basic rendering functions
 * such as "render this texture there with this angle".
 * 
 * It could be implemented differently on different platforms.
 * For now, only SDL2 renderer is implemented.
 */

/// @brief Mode of the renderer window (fullscreen or not or etc.).
enum RendererMode
{
    RR_MODE_FULLSCREEN = 0, // Renderer opens in fullscreen. Provided resolution is ignored.
    RR_MODE_WINDOW          // Renderer opens a window instead. Its resolution must be defined.
};

/// @brief Various params to set for the renderer environment such as resolution.
struct RendererParams
{
    /// @brief Value that returns real window size when multiplied with game resolution.
    ///
    /// E.g. `GAME_RES * scale = WINDOW_SIZE`
    /// => `{1280:720} * 1.5 = {1920:1080}`
    float scale = 1;

    /// @brief Desired mode of the renderer window
    /// (see enum RendererMode).
    RendererMode renderer_mode = RR_MODE_FULLSCREEN;

    /// @brief Desired size of the physical renderer window in pixels.
    /// If you go fullscreen, leave 0 as renderer will occupy the whole screen anyway.
    ///
    /// The game resolution will get smaller if you provide a scale >1.
    int width = 0, height = 0;
};

/// @brief Little struct representing a color with an alpha channel.
struct RendererColor
{
    const char red = (char)0;       // Quantity of the red color (0-255).
    const char green = (char)0;     // Quantity of the green color (0-255).
    const char blue = (char)0;      // Quantity of the blue color (0-255).
    const char alpha = (char)255;   // Alpha channel (opacity) (0-255).
};

/**
 * @brief Renderer implementation.
 * 
 * Refer to the current platform source .cpp file to know which implementation this is.
 * 
 * When created, Renderer does nothing. To init the graphics environment, call `init()`
 * passing the `rendererParams` struct if you need to overwrite default params
 * (that is, software fullscreen window. You pass the struct to launch in a window for example).
 */
class BaseRenderer
{
public:
    virtual ~BaseRenderer() {};

    /// @brief Init the graphical environment (create a window and its renderer).
    /// @param rendererParams RendererParams to overwrite if needed.
    /// @return True if could init correctly. False if not.
    virtual bool init(RendererParams rendererParams = RendererParams()) = 0;

    /// @brief Set the new renderer params when need to update.
    ///
    /// It won't init the renderer. Call `init()` instead.
    /// @param rendererParams New RendererParams.
    virtual void setParams(RendererParams rendererParams) = 0;

    /// @brief Get current width of the game env in pixels.
    /// Game window might be bigger though. Refer to `getScale()`.
    ///
    /// Still, you need to consider this resolution when rendering.
    /// @return 0 if didn't yet init renderer.
    virtual int getWidth() = 0;

    /// @brief Get current height of the game env in pixels.
    /// Game window might be bigger though. Refer to `getScale()`.
    ///
    /// Still, you need to consider this resolution when rendering.
    /// @return 0 if didn't yet init renderer.
    virtual int getHeight() = 0;

    /// @brief Get a value that gives the physical size of the renderer window when
    /// multiplied with the game env size (`getWidth()` and `getHeight()`).
    /// @return 0 if didn't yet init renderer.
    virtual float getScale() = 0;

    /// @brief Get time between two renders in milliseconds.
    /// @return 0 if didn't yet init renderer.
    virtual float getDelta() = 0;

    /// @brief Get rendered frames count since the renderer init.
    /// @return 0 if didn't yet init renderer.
    virtual unsigned long int getFrames() = 0;

    /// @brief Fill the whole screen with a single color.
    /// @param color Desired color of the screen (background even).
    virtual void clearScreen(RendererColor color) = 0;

    /// @brief Swap the renderer buffer and show everything that was rendered.
    virtual void render() = 0;

protected:
    /// @brief Is the renderer inited and ready to use?
    bool m_IsInited;

    /// @brief Quantity of frames that were rendered since the renderer init.
    unsigned long int m_Frames;

    /// @brief Current size of the physical renderer window. 0 by default when not inited.
    ///
    /// Note `m_Scale`.
    int m_WindowWidth, m_WindowHeight;

    /// @brief Current size of the game environment. 0 by default when not inited.
    ///
    /// Note `m_Scale`.
    int m_GameWidth, m_GameHeight;

    /// @brief Value that returns real window size when multiplied with game resolution.
    ///
    /// E.g. `GAME_RES * scale = WINDOW_SIZE`
    /// => `{1280:720} * 1.5 = {1920:1080}`
    float m_Scale;
};
