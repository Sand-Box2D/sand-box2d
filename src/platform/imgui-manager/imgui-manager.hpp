#pragma once

#include "../../lib/imgui/imgui.h"

#include "../renderer/renderer.hpp"

/**
 * @brief Manager setting up Dear ImGui.
 * 
 * As Dear ImGui requires some of its proper config on different platforms,
 * this platform-specific module was introduced.
 * 
 * When created, manager inits Dear ImGui and binds it to your renderer.
 */
class ImGuiManager
{
public:
    /// @brief Init manager of the Dear ImGui.
    /// @param r_renderer Your referenced Renderer object
    /// is required to init Dear ImGui. 
    ImGuiManager(Renderer &r_renderer);
    ~ImGuiManager();
};
