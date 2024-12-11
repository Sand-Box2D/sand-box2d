/// @brief Platform-specific module of Dear ImGui manager. See class `ImGuiManager`.

#pragma once

#include "imgui.h" // IWYU pragma: export

#include "platform/renderer/renderer.hpp"

/**
 * @brief Manager setting up Dear ImGui.
 * 
 * As Dear ImGui requires some of its proper config on different platforms,
 * this platform-specific module was introduced.
 * 
 * When created, manager does nothing.
 * Call `init()` passing your Renderer object to init the manager.
 */
class ImGuiManager
{
public:
    ImGuiManager();
    ~ImGuiManager();

    /// @brief Init the Dear ImGui manager binding it to the Renderer.
    /// @param r_renderer Your referenced Renderer object is required to init Dear ImGui. 
    void init(Renderer &r_renderer);

    /// @brief Make a logical step of the Dear ImGui manager.
    ///
    /// Requires to be launched after calling `processEvent()`.
    void step();

    /// @brief Render everything that ImGui was asked to render.
    /// @param r_renderer Renderer is required to render stuff.
    void render(Renderer &r_renderer);

private:
};
