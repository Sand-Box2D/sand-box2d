/// @brief This provides a declaration of the main class of the game, `GameManager`.

#pragma once

#include "platform/renderer/renderer.hpp"
#include "platform/controls/controls.hpp"

#include "system/scene-manager.hpp"

/**
 * @brief GameManager is the principal class of the game. It manages all.
 * 
 * It is responsible for creating, storaging and linking up everything.
 * 
 * When created, GM sets everything up but does nothing.
 * In order to tell it to "run the game", call `step()` and then `render()` in the loop
 * (e.g. `while (gm.step()) {gm.render();}`).
 */
class GameManager
{
public:
    GameManager();
    ~GameManager();

    /// @brief Make a logical step of the game.
    ///
    /// It will decide which scene should be executed.
    /// For more info refer to `models/scenes/scene.hpp`.
    /// @return False when game has to be closed now.
    bool step();

    /// @brief Render current scene.
    void render();

private:
    /// @brief Renderer of the game.
    ///
    /// Renderer is a class which represents basic renderer functions.
    /// To know more about it, see class `Renderer`.
    Renderer m_Renderer;

    /// @brief Object providing state of the currently pressed buttons.
    Controls m_Controls;

    /// @brief Object providing state of the buttons pressed in the previous frame.
    Controls m_OldControls;

    /// @brief Object allowing us to work with all the game scenes.
    SceneManager m_SceneManager;
};
