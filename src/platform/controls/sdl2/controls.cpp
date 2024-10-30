/**
 * @brief SDL2 Implementation for Controls.
 * 
 * Uses SDL2 input handling poll system
 * in order to know which keys are pressed or which buttons are tapped with SDL2_Controller.
 * 
 * Used in all the PC builds.
 */

#include "../controls.hpp"

#include <SDL2/SDL.h>

#include "lib/imgui/backends/imgui_impl_sdl2.h"

/// @brief SDL2 Controls specific data.
struct ControlsSpecific {};

Controls::Controls() {}
Controls::~Controls() {}

void Controls::check()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            Controls::isQuit = true;
            break;

        default:
            break;
        }
    }
}

bool Controls::getQuit()
{
    return Controls::isQuit;
}
