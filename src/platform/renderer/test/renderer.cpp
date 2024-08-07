#include "../renderer.hpp"

#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

/**
 * @brief Test Implementation for Renderer.
 * 
 * This is a throw-off placeholder copy of SDL2 Renderer impl.
 * to see if it won't compile (normally it doesn't).
 * 
 * You shouldn't open such a file with your IDE as you'll see
 * a lot of errors (that's sort of an example of a real code for another platform).
 */

/// @brief Window for the SDL2 Renderer impl.
SDL_Window *mp_Window;

/// @brief Renderer for this SDL2 impl.
SDL_Renderer *mp_Renderer;

Renderer::Renderer()
{
    // I'll do some gibberish to see what happens
    eirhbfieurbfiuerhfeijebnrf();
    OOIIOFIJOP@EF OI#@JFOIF;
    Iufnorfmmf
    FUEYCUHE_EFWIHBEFE__ EFEWFEWFWEFWEFRWEFWEF'''

    mp_Window = nullptr;
    mp_Renderer = nullptr;

    Renderer::m_IsInited = false;
    Renderer::m_Frames = 0;

    Renderer::m_WindowWidth = 0;
    Renderer::m_WindowHeight = 0;

    Renderer::m_GameWidth = 0;
    Renderer::m_GameHeight = 0;

    Renderer::m_Scale = 0;
}
Renderer::~Renderer()
{
    if (!Renderer::m_IsInited)
        return;

    SDL_DestroyRenderer(mp_Renderer);
    SDL_DestroyWindow(mp_Window);
}

bool Renderer::init(RendererParams rendererParams)
{
    try
    {
        Renderer::m_IsInited = false;
        Renderer::m_Frames = 0;

        SDL_Init(SDL_INIT_EVERYTHING);

        switch (rendererParams.renderer_mode)
        {
        case RR_MODE_FULLSCREEN:
            SDL_DisplayMode dm;
            SDL_GetCurrentDisplayMode(0, &dm);

            Renderer::m_WindowWidth = dm.w;
            Renderer::m_WindowHeight = dm.h;

            mp_Window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                Renderer::m_WindowWidth,
                Renderer::m_WindowHeight,
                SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        case RR_MODE_WINDOW:
            Renderer::m_WindowWidth = rendererParams.width;
            Renderer::m_WindowHeight = rendererParams.height;

            mp_Window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                Renderer::m_WindowWidth,
                Renderer::m_WindowHeight,
                SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        default:
            throw std::invalid_argument("Please select the renderer mode!");
        }

        Renderer::m_Scale = rendererParams.scale;

        Renderer::m_GameWidth = Renderer::m_WindowWidth / Renderer::m_Scale;
        Renderer::m_GameHeight = Renderer::m_WindowHeight / Renderer::m_Scale;

        mp_Renderer = SDL_CreateRenderer(
            mp_Window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        SDL_SetWindowSize(
            mp_Window,
            Renderer::m_WindowWidth,
            Renderer::m_WindowHeight
        );
        SDL_RenderSetLogicalSize(
            mp_Renderer,
            Renderer::m_WindowWidth,
            Renderer::m_WindowHeight
        );

        if (rendererParams.renderer_mode == RR_MODE_WINDOW)
            SDL_SetWindowPosition(mp_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

        Renderer::m_IsInited = true;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

void Renderer::setParams(RendererParams rendererParams)
{
    if (!Renderer::m_IsInited)
        return;

    switch (rendererParams.renderer_mode)
    {
    case RR_MODE_FULLSCREEN:
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);

        Renderer::m_WindowWidth = dm.w;
        Renderer::m_WindowHeight = dm.h;

        SDL_SetWindowFullscreen(mp_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);

        break;

    case RR_MODE_WINDOW:
        Renderer::m_WindowWidth = rendererParams.width;
        Renderer::m_WindowHeight = rendererParams.height;

        SDL_SetWindowFullscreen(mp_Window, 0);

        break;

    default:
        break;
    }

    Renderer::m_Scale = rendererParams.scale;

    Renderer::m_GameWidth = Renderer::m_WindowWidth / Renderer::m_Scale;
    Renderer::m_GameHeight = Renderer::m_WindowHeight / Renderer::m_Scale;

    SDL_SetWindowSize(
        mp_Window,
        Renderer::m_WindowWidth,
        Renderer::m_WindowHeight
    );
    SDL_RenderSetLogicalSize(
        mp_Renderer,
        Renderer::m_WindowWidth,
        Renderer::m_WindowHeight
    );

    if (rendererParams.renderer_mode == RR_MODE_WINDOW)
        SDL_SetWindowPosition(mp_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

int Renderer::getWidth()
{
    return Renderer::m_GameWidth;
}

int Renderer::getHeight()
{
    return Renderer::m_GameHeight;
}

float Renderer::getScale()
{
    return m_Scale;
}

float Renderer::getDelta()
{
    const float placeholder_delta = 16.6; // TODO
    return placeholder_delta;
}

unsigned long int Renderer::getFrames()
{
    return m_Frames;
}

void Renderer::clearScreen(RendererColor color)
{
    SDL_SetRenderDrawColor(
        mp_Renderer,
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    SDL_RenderClear(mp_Renderer);
}

void Renderer::render()
{
    SDL_RenderPresent(mp_Renderer);
}
