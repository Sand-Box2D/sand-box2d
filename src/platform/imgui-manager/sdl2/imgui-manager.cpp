#include "../imgui-manager.hpp"

#include "../../../lib/imgui/backends/imgui_impl_sdl2.h"
#include "../../../lib/imgui/backends/imgui_impl_sdlrenderer2.h"

/**
 * @brief SDL2 Implementation of the Dear ImGui Manager.
 * 
 * This implementation works with SDL2 window and its renderer.
 * 
 * It might not work on PS Vita. If it doesn't,
 * create a new implementation named `sdl2-vita`.
 */

ImGuiManager::ImGuiManager() {}
ImGuiManager::~ImGuiManager() {}

void ImGuiManager::init(Renderer *r_renderer) {}