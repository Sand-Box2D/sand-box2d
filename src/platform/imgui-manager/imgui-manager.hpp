/// @brief Platform-specific module of Dear ImGui manager. See class `ImGuiManager`.

#pragma once

#include "../../lib/imgui/imgui.h"

#include "../renderer/renderer.hpp"
#include "../controls/controls.hpp"

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
    virtual ~ImGuiManager() = 0;

    /// @brief Init the Dear ImGui manager binding it to the Renderer.
    /// @param r_renderer Your referenced Renderer object is required to init Dear ImGui. 
    virtual void init(Renderer &r_renderer) = 0;

    /// @brief Make a logical step of the Dear ImGui manager.
    ///
    /// Requires to be launched after calling `processInputs()`.
    virtual void step() = 0;

    /// @brief Render everything that ImGui was asked to render.
    /// @param r_renderer Renderer is required to render stuff.
    virtual void render(Renderer &r_renderer) = 0;

    /// @brief Pass current Controls to ImGui so it will navigate.
    /// @param r_controls Current Controls object to be passed before handling it anywhere else.
    virtual void processInputs(Controls &r_controls) = 0;

    /// @brief Tell whether Dear ImGui wants to capture your keyboard inputs so you won't handle them.
    /// @return True if you need to stop handling keyboard inputs. False if not.
    virtual bool getCaptureKeyboard() = 0;

    /// @brief Tell whether Dear ImGui wants to capture your mouse so you won't handle it.
    /// @return True if you need to stop handling mouse. False if not.
    virtual bool getCaptureMouse() = 0;
};
