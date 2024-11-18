/**
 * @brief SDL2 Implementation for Controls.
 * 
 * Uses SDL2 input handling poll system
 * in order to know which keys are pressed or which buttons are tapped with SDL2_Controller.
 * 
 * Also it passes the SDL2 input event to Dear ImGui.
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

        auto imgui_io = ImGui::GetIO();
        bool imgui_wants_keyboard = imgui_io.WantCaptureKeyboard;
        bool imgui_wants_mouse = imgui_io.WantCaptureMouse;

        switch (event.type)
        {
        case SDL_QUIT:
            Controls::isQuit = true;
            break;

        // Hint: ? 1 : 0 at the end is a conversion to the analog value.
        case SDL_KEYDOWN: case SDL_KEYUP:
            if (imgui_wants_keyboard)
                break;

            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_UP:
                Controls::isMenuUp = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_DOWN:
                Controls::isMenuDown = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_LEFT:
                Controls::isMenuLeft = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_RIGHT:
                Controls::isMenuRight = event.type == SDL_KEYDOWN;
                break;

            case SDL_SCANCODE_W:
                Controls::isMenuUp = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_S:
                Controls::isMenuDown = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_A:
                Controls::isMenuLeft = event.type == SDL_KEYDOWN;
                break;
            case SDL_SCANCODE_D:
                Controls::isMenuRight = event.type == SDL_KEYDOWN;
                break;
            
            default:
                break;
            }

            break;

        default:
            break;
        }
    }
}

bool Controls::getQuit()            { return Controls::isQuit; }

bool Controls::getMenuUp()          { return Controls::isMenuUp; }
bool Controls::getMenuDown()        { return Controls::isMenuDown; }
bool Controls::getMenuLeft()        { return Controls::isMenuLeft; }
bool Controls::getMenuRight()       { return Controls::isMenuRight; }
