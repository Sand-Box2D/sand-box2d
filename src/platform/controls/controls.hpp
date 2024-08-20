#pragma once

#include <memory>

/**
 * @brief Controls class provides you the state of the pressed "buttons" in game.
 * 
 * Buttons and their handling is hardly linked. Button remapping is a to-do.
 * 
 * Such buttons as "close this menu" are returning the boolean (binary out),
 * While some other actions as "zoom in" might actually return a float between
 * 0 and 1. This is due to the fact that these buttons could be clicked with a 
 * different force on certain platforms.
 * 
 * It is generally suggested to have two "Controls" objects:
 * one showing the state of controls in this frame and another in the previous.
 * Like this, it's very easy to handle keyups/keydowns `(now && !old)`.
 */

/// @brief Declaration of platform-specific Controls data.
struct ControlsSpecific;

/// @brief Class allowing you to access currently pressed buttons.
///
/// When created, Controls does nothing.
/// You have to call `check()` to query pressed buttons.
/// You can then access their states by calling various methods of this class.
class Controls
{
public:
    Controls();
    ~Controls();

    /// @brief Query pressed buttons.
    ///
    /// This puts their states to private variables of this object
    /// you can access with public methods.
    void check();

    /// @brief Get state of the action telling game to close.
    ///
    /// Has to be handled.
    /// @return True if game has to be closed now.
    bool getQuit();

private:
    /// @brief Pointer to platform-specific Controls data.
    std::shared_ptr<ControlsSpecific> mp_Specific;

    /// @brief State of the action telling game to close.
    bool isQuit = false;
};
