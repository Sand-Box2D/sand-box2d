/// @brief This provides a declaration of the class managing scenes, `SceneManager`.

#pragma once

#include "../models/scenes/scene.hpp"
#include "../models/scenes/scene-main.hpp"

/**
 * @brief Manager of the game scenes.
 * 
 * See more about what a scene is: `models/scenes/scene.hpp`.
 * 
 * When created, manager does nothing. Call `init()` passing the enum value
 * representing a scene to be inited (see enum `CurrentScene`).
 * 
 * Then, call `step()` and `render()` in a loop.
 * When `step()` returns false, game has to be closed now
 * (due to some action done inside a scene, like hit the exit button in the main menu).
 */
class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    /// @brief Init the SceneManager and its first scene.
    /// @param scene_to_init Describes which scene should be inited first.
    void init(CurrentScene scene_to_init);

    /// @brief Make a logical step of the scene manager.
    ///
    /// When executed, this function runs a step on the current scene.
    /// If it returns true, nothing else happens and this method returns.
    /// But if it returned false, SManager asks the current scene which scene should be inited next
    /// and whether it asks to retain its context.
    /// After doing so, it inits the new scene and reruns the step for it.
    /// @param r_renderer Access the Renderer object to know the rendering context (delta etc.).
    /// @param r_controls Used to read currently pressed buttons.
    /// @param r_old_controls Used to read buttons pressed in the previous frame.
    /// @return False when game has to be closed now
    /// (due to some action done inside a scene, like hit the exit button in the main menu).
    bool step
    (
        Renderer &r_renderer,
        Controls &r_controls,
        Controls &r_old_controls
    );

    /// @brief Render current scene.
    /// @param r_renderer Access the Renderer object to render stuff.
    void render(Renderer &r_renderer);

private:
    /// @brief Make a logical step of a scene and return its result.
    /// @param scene_to_process Scene to make a step for.
    /// @return Whether this scene wants to make a next step or not.
    // bool stepScene(CurrentScene scene_to_process);

    /// @brief Whether this manager was already inited and ready to use.
    bool m_IsInited = false;

    /// @brief Value representing which scene is currently used.
    CurrentScene m_CurrentScene;

    /// @brief Main Menu Scene.
    SceneMain m_SceneMain;
};
