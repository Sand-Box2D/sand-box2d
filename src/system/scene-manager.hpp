/// @brief This provides a declaration of the class managing scenes, `SceneManager`.

#pragma once

#include "../models/scenes/scene.hpp"

#include "../models/scenes/scene-main.hpp"
#include "../models/scenes/scene-test1.hpp"
#include "../models/scenes/scene-test2.hpp"

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
    /// To know what manager does in this function, refer to `models/scenes/scene.hpp`.
    /// @param r_renderer Access the Renderer object to know the rendering context (delta etc.).
    /// @param r_controls Used to read currently pressed buttons.
    /// @param r_old_controls Used to read buttons pressed in the previous frame.
    /// @return False when game has to be closed now
    /// (due to some action done inside a scene, like hit the exit button in the main menu).
    bool step(
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
    /// @brief test1.
    SceneTestOne m_SceneTestOne;
    /// @brief test2.
    SceneTestTwo m_SceneTestTwo;

    /// @brief Execute a step on a scene and do nothing else.
    /// @param scene_to_execute Corresponding scene to execute a step on.
    /// @param r_renderer Access the Renderer object to know the rendering context (delta etc.).
    /// @param r_controls Used to read currently pressed buttons.
    /// @param r_old_controls Used to read buttons pressed in the previous frame.
    /// @return Whether this scene declares that it finished its job.
    /// True if scene asks to also use it in the next frame.
    /// False if it's done and now you can / have to switch to other.
    bool m_ExecuteOneStep(
        CurrentScene scene_to_execute,
        Renderer &r_renderer,
        Controls &r_controls,
        Controls &r_old_controls
    );

    /// @brief Does this scene want to close the entire game now?
    /// @param scene_to_execute Corresponding scene to get the info from.
    /// @return True if the game has to be closed now.
    bool m_GetExitScene(CurrentScene scene_to_query);

    /// @brief Get data about which scene you have to switch to.
    /// @param scene_to_execute Corresponding scene to get the info from.
    /// @return Struct containing info about what scene should be the next.
    NextScene m_GetNextScene(CurrentScene scene_to_query);
};
