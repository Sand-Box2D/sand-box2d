#include "renderer-sdl2.hpp"

RendererSdl2::RendererSdl2()
{
    RendererSdl2::m_IsInited = false;
    RendererSdl2::m_Frames = 0;

    RendererSdl2::m_WindowWidth = 0;
    RendererSdl2::m_WindowHeight = 0;

    RendererSdl2::m_GameWidth = 0;
    RendererSdl2::m_GameHeight = 0;

    RendererSdl2::m_Scale = 0;
}
RendererSdl2::~RendererSdl2()
{
    SDL_DestroyRenderer(RendererSdl2::mp_Renderer);
    SDL_DestroyWindow(RendererSdl2::mp_Window);
}

bool RendererSdl2::init(RendererParams rendererParams)
{
    try
    {
        RendererSdl2::m_IsInited = false;
        RendererSdl2::m_Frames = 0;

        SDL_Init(SDL_INIT_EVERYTHING);

        switch (rendererParams.renderer_mode)
        {
        case RR_MODE_FULLSCREEN:
            SDL_DisplayMode dm;
            SDL_GetCurrentDisplayMode(0, &dm);

            RendererSdl2::m_WindowWidth = dm.w;
            RendererSdl2::m_WindowHeight = dm.h;

            RendererSdl2::mp_Window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                RendererSdl2::m_WindowWidth,
                RendererSdl2::m_WindowHeight,
                SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        case RR_MODE_WINDOW:
            RendererSdl2::m_WindowWidth = rendererParams.width;
            RendererSdl2::m_WindowHeight = rendererParams.height;

            RendererSdl2::mp_Window = SDL_CreateWindow(
                "Sand-Box2D",
                0,
                0,
                RendererSdl2::m_WindowWidth,
                RendererSdl2::m_WindowHeight,
                SDL_WINDOW_INPUT_GRABBED | SDL_WINDOW_ALLOW_HIGHDPI
            );

            break;

        default:
            throw std::invalid_argument("Please select the renderer mode!");
        }

        RendererSdl2::m_Scale = rendererParams.scale;

        RendererSdl2::m_GameWidth = RendererSdl2::m_WindowWidth / RendererSdl2::m_Scale;
        RendererSdl2::m_GameHeight = RendererSdl2::m_WindowHeight / RendererSdl2::m_Scale;

        RendererSdl2::mp_Renderer = SDL_CreateRenderer(
            RendererSdl2::mp_Window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );

        SDL_SetWindowSize(
            RendererSdl2::mp_Window,
            RendererSdl2::m_WindowWidth,
            RendererSdl2::m_WindowHeight
        );
        SDL_RenderSetLogicalSize(
            RendererSdl2::mp_Renderer,
            RendererSdl2::m_WindowWidth,
            RendererSdl2::m_WindowHeight
        );

        if (rendererParams.renderer_mode == RR_MODE_WINDOW)
            SDL_SetWindowPosition(RendererSdl2::mp_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

        RendererSdl2::m_IsInited = true;
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

void RendererSdl2::setParams(RendererParams rendererParams)
{
    if (!RendererSdl2::m_IsInited)
        return;

    switch (rendererParams.renderer_mode)
    {
    case RR_MODE_FULLSCREEN:
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);

        RendererSdl2::m_WindowWidth = dm.w;
        RendererSdl2::m_WindowHeight = dm.h;

        SDL_SetWindowFullscreen(RendererSdl2::mp_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);

        break;

    case RR_MODE_WINDOW:
        RendererSdl2::m_WindowWidth = rendererParams.width;
        RendererSdl2::m_WindowHeight = rendererParams.height;

        SDL_SetWindowFullscreen(RendererSdl2::mp_Window, 0);

        break;

    default:
        break;
    }

    RendererSdl2::m_Scale = rendererParams.scale;

    RendererSdl2::m_GameWidth = RendererSdl2::m_WindowWidth / RendererSdl2::m_Scale;
    RendererSdl2::m_GameHeight = RendererSdl2::m_WindowHeight / RendererSdl2::m_Scale;

    SDL_SetWindowSize(
        RendererSdl2::mp_Window,
        RendererSdl2::m_WindowWidth,
        RendererSdl2::m_WindowHeight
    );
    SDL_RenderSetLogicalSize(
        RendererSdl2::mp_Renderer,
        RendererSdl2::m_WindowWidth,
        RendererSdl2::m_WindowHeight
    );

    if (rendererParams.renderer_mode == RR_MODE_WINDOW)
        SDL_SetWindowPosition(RendererSdl2::mp_Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

int RendererSdl2::getWidth()
{
    return RendererSdl2::m_GameWidth;
}

int RendererSdl2::getHeight()
{
    return RendererSdl2::m_GameHeight;
}

float RendererSdl2::getScale()
{
    return m_Scale;
}

float RendererSdl2::getDelta()
{
    const float placeholder_delta = 16.6; // TODO
    return placeholder_delta;
}

unsigned long int RendererSdl2::getFrames()
{
    return m_Frames;
}

void RendererSdl2::clearScreen(RendererColor color)
{
    SDL_SetRenderDrawColor(
        RendererSdl2::mp_Renderer,
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    SDL_RenderClear(RendererSdl2::mp_Renderer);
}

void RendererSdl2::render()
{
    SDL_RenderPresent(RendererSdl2::mp_Renderer);
}
