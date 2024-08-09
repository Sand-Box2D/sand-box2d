#pragma once

#include "platform/renderer/renderer.hpp"
#include "platform/controls/controls.hpp"

/**
 * @brief GameManager is the principal class of the game. It manages all.
 * 
 * It is responsible for creating, storaging and linking up everything.
 */

/// @brief Manager of the entirety of the game.
///
/// When created, GM sets everything up but does nothing.
/// In order to tell it to "run the game", call `cycle()`.
class GameManager
{
public:
    GameManager();
    ~GameManager();

    /// @brief Launch the game main cycle.
    void cycle();
private:
    /// @brief Make a logical step of the game.
    ///
    /// It will decide which scene should be executed.
    /// For more info refer to `models/scenes/scene.hpp`.
    /// @return False when game has to be closed now.
    bool m_step();

    /// @brief Render current scene.
    void m_render();

    /// @brief Renderer of the game.
    ///
    /// Renderer is a class which represents basic renderer functions.
    /// To know more about it, see class `Renderer`.
    Renderer m_Renderer;

    /// @brief Object providing state of the currently pressed buttons.
    Controls m_Controls;

    /// @brief Object providing state of the buttons pressed in the previous frame.
    Controls m_OldControls;
};
