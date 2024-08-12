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
 * (GLFW / bare OpenGL and Metal implementations might appear later).
 */

/// @brief SDL2 Renderer impl. specific data.
struct RendererSpecific
{
    /// @brief Window for the SDL2 Renderer impl.
    SDL_Window *p_window = nullptr;

    /// @brief Renderer for this SDL2 impl.
    SDL_Renderer *p_renderer = nullptr;
};

Renderer::Renderer()
{
    Renderer::mp_Specific = std::make_unique<RendererSpecific>();

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

    SDL_DestroyRenderer(Renderer::mp_Specific->p_renderer);
    SDL_DestroyWindow(Renderer::mp_Specific->p_window);
}

bool Renderer::init(RendererParams rendererParams)
{
    try
    {
        Renderer::m_IsInited = false;
        Renderer::m_Frames = 0;

        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_DisplayMode display_mode;
        SDL_GetCurrentDisplayMode(0, &display_mode);

        switch (rendererParams.renderer_mode)
        {
        case RR_MODE_FULLSCREEN_SOFT:
            Renderer::m_WindowWidth = display_mode.w;
            Renderer::m_WindowHeight = display_mode.h;

            Renderer::mp_Specific->p_window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                Renderer::m_WindowWidth,
                Renderer::m_WindowHeight,
                SDL_WINDOW_FULLSCREEN_DESKTOP
                    | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        case RR_MODE_FULLSCREEN_HARD:
            Renderer::m_WindowWidth = rendererParams.width == 0
                ? display_mode.w
                : rendererParams.width;
            Renderer::m_WindowHeight = rendererParams.height == 0
                ? display_mode.h
                : rendererParams.height;

            Renderer::mp_Specific->p_window = SDL_CreateWindow(
                "Sand-Box2D",   // je fais expres de hardcoder celui-ci mdr
                0,
                0,
                Renderer::m_WindowWidth,
                Renderer::m_WindowHeight,
                SDL_WINDOW_FULLSCREEN
                    | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        case RR_MODE_WINDOW:
            Renderer::m_WindowWidth = rendererParams.width;
            Renderer::m_WindowHeight = rendererParams.height;

            Renderer::mp_Specific->p_window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                Renderer::m_WindowWidth,
                Renderer::m_WindowHeight,
                SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        default:
            throw std::invalid_argument("Please select the renderer mode!");
        }

        Renderer::m_Scale = rendererParams.scale;

        Renderer::m_GameWidth = Renderer::m_WindowWidth / Renderer::m_Scale;
        Renderer::m_GameHeight = Renderer::m_WindowHeight / Renderer::m_Scale;

        Renderer::mp_Specific->p_renderer = SDL_CreateRenderer(
            Renderer::mp_Specific->p_window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        SDL_SetWindowSize(
            Renderer::mp_Specific->p_window,
            Renderer::m_WindowWidth,
            Renderer::m_WindowHeight
        );
        SDL_RenderSetLogicalSize(
            Renderer::mp_Specific->p_renderer,
            Renderer::m_WindowWidth,
            Renderer::m_WindowHeight
        );

        if (rendererParams.renderer_mode == RR_MODE_WINDOW)
            SDL_SetWindowPosition(
                Renderer::mp_Specific->p_window,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED
            );

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

    SDL_DisplayMode display_mode;
    SDL_GetCurrentDisplayMode(0, &display_mode);

    switch (rendererParams.renderer_mode)
    {
    case RR_MODE_FULLSCREEN_SOFT:
        Renderer::m_WindowWidth = display_mode.w;
        Renderer::m_WindowHeight = display_mode.h;

        SDL_SetWindowFullscreen(
            Renderer::mp_Specific->p_window,
            SDL_WINDOW_FULLSCREEN_DESKTOP
        );

        break;

    case RR_MODE_FULLSCREEN_HARD:
        Renderer::m_WindowWidth = rendererParams.width == 0
            ? display_mode.w
            : rendererParams.width;
        Renderer::m_WindowHeight = rendererParams.height == 0
            ? display_mode.h
            : rendererParams.height;

        SDL_SetWindowFullscreen(
            Renderer::mp_Specific->p_window,
            SDL_WINDOW_FULLSCREEN
        );

        break;

    case RR_MODE_WINDOW:
        Renderer::m_WindowWidth = rendererParams.width;
        Renderer::m_WindowHeight = rendererParams.height;

        SDL_SetWindowFullscreen(Renderer::mp_Specific->p_window, 0);

        break;

    default:
        break;
    }

    Renderer::m_Scale = rendererParams.scale;

    Renderer::m_GameWidth = Renderer::m_WindowWidth / Renderer::m_Scale;
    Renderer::m_GameHeight = Renderer::m_WindowHeight / Renderer::m_Scale;

    SDL_SetWindowSize(
        Renderer::mp_Specific->p_window,
        Renderer::m_WindowWidth,
        Renderer::m_WindowHeight
    );
    SDL_RenderSetLogicalSize(
        Renderer::mp_Specific->p_renderer,
        Renderer::m_WindowWidth,
        Renderer::m_WindowHeight
    );

    if (rendererParams.renderer_mode == RR_MODE_WINDOW)
        SDL_SetWindowPosition(
            Renderer::mp_Specific->p_window,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED
        );
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
    const float PLACEHOLDER_DATA = 16.6; // TODO
    return PLACEHOLDER_DATA;
}

unsigned long int Renderer::getFrames()
{
    return m_Frames;
}

void Renderer::clearScreen(RendererColor color)
{
    SDL_SetRenderDrawColor(
        Renderer::mp_Specific->p_renderer,
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    SDL_RenderClear(Renderer::mp_Specific->p_renderer);
}

void Renderer::render()
{
    SDL_RenderPresent(Renderer::mp_Specific->p_renderer);
}
