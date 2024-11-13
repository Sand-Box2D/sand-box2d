/**
 * @brief PS Vita SDL2 Implementation of the Dear ImGui Manager.
 * 
 * This implementation works with SDL2 window and its renderer.
 * 
 * This is SDL2 implementation adapted for PS Vita.
 * Do not use it in another platforms.
 */

#include "../imgui-manager.hpp"

// #include "lib/imgui/backends/imgui_impl_sdl2.h"
// #include "lib/imgui/backends/imgui_impl_sdlrenderer2.h"

ImGuiManager::ImGuiManager() {}
ImGuiManager::~ImGuiManager()
{
    // ImGui_ImplSDLRenderer2_Shutdown();
    // ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiManager::init(Renderer &r_renderer)
{
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // auto window = r_renderer.getWindow<SDL_Window*>();
    // auto renderer = r_renderer.getRenderer<SDL_Renderer*>();

    // ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    // ImGui_ImplSDLRenderer2_Init(renderer);
}

void ImGuiManager::step()
{
    // ImGui_ImplSDLRenderer2_NewFrame();
    // ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void ImGuiManager::render(Renderer &r_renderer)
{
    ImGui::Render();
    // ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), r_renderer.getRenderer<SDL_Renderer*>());
}

void ImGuiManager::showDemoWindow(bool *p_open)
{
    // nothing...
}
