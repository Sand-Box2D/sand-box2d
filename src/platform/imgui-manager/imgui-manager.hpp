#pragma once

#include "../../lib/imgui/imgui.h"

#include "../renderer/renderer.hpp"

/**
 * @brief Manager setting up Dear ImGui.
 * 
 * As Dear ImGui requires some of its proper config on different platforms,
 * this platform-specific module was introduced.
 */

/// @brief Class managing the Dear ImGui for you.
///
/// When created, manager does nothing.
/// To init Dear ImGui, call `init()` passing your Renderer object.
class ImGuiManager
{
public:
    ImGuiManager();
    ~ImGuiManager();

    /// @brief Init manager of the Dear ImGui.
    /// @param r_renderer Your referenced Renderer object
    /// is required to init Dear ImGui.
    void init(Renderer *r_renderer);
};
