/// @brief This provides the interface of a scene, `IScene`.

#pragma once

#include "../../platform/renderer/renderer.hpp"
#include "../../platform/controls/controls.hpp"

/// @brief Enum describing which scene should be shown now.
enum CurrentScene
{
    SCENE_MAIN = 0                  // Scene of the main menu. `SceneMain`.
};

/// @brief Struct containing info about what scene should be the next.
struct NextScene
{
    /// @brief Which scene has to be inited.
    CurrentScene asked_scene = SCENE_MAIN;

    /// @brief If true, previous scene asks to not call `free()` on it.
    ///
    /// Like this, you can seamlessly "return" to it. Don't call `init()` on it then.
    bool retain_context = false;
};

/**
 * @brief Interface for a scene,
 * an object that possesses all the screen area at this moment.
 * 
 * Is managed by SceneManager. This manager does the following:
 * 
 * 1. First, we should say that there are 4 actions a scene can do:
 * init, free, step & render.
 * 
 * 2. SceneManager has to decide which scene needs to be inited (call `init()`).
 * 
 * 3. SceneManager executes "step" on that scene.
 * 
 * 4. If scene returns true, SceneManager will render the same scene later
 * and redo the step for it.
 * 
 * 5. If false returned, SceneManager will decide which scene should be the next
 * by querying the closing scene (like SceneMain tells us to open SceneSettings).
 * 
 * 6. If scene didn't ask to retain its context, SManager frees its resources.
 * 
 * 7. Then, it will init the new scene and rerun the check which scene should execute "step".
 * 
 * 8. After doing so it will eventually render the new scene.
 * 
 * Notice how SManager didn't render scene when it returned false.
 * We can do a little schema (0Step is one scene, 1Step is another):
 * 
 * 0Step (true) -> 0Render -> 0Step (false) -> 1Init -> 1Step (true) -> 1Render -> 1Step...
 * 
 * Generally, the idea is that there is only one single IScene object
 * which is shown at the same time. When moving to another scene, old one frees memory.
 * 
 * But also, a scene can ask to retain memory even when not active.
 * Like this, we can get back to it quickly while retaining all its context.
 * Imagine playing a level, opening Settings from the Pause, and getting back to level.
 * 
 * When created, scene does nothing. You should call `init()` to allocate resources.
 * Then, call `step()` and `render()` in a loop. When `step()` returns false,
 * query which screen should be inited next with `getNext()`
 * and whether this window asks to not `free()` context of it.
 */
class IScene
{
public:
    virtual ~IScene() {};

    /// @brief Allocate memory and set default settings for this scene.
    ///
    /// You can define another init function taking some parameters (like level to be loaded).
    /// But this one has to be defined also. Make it run the same thing but with default params.
    virtual void init() = 0;

    /// @brief Free all the memory associated with this scene.
    ///
    /// To be assured, this is automatically called in the destructor.
    virtual void free() = 0;

    /// @brief Make a logical step of this scene.
    /// @param r_renderer Access the Renderer object to know the rendering context (delta etc.).
    /// @param r_controls Used to read currently pressed buttons.
    /// @param r_old_controls Used to read buttons pressed in the previous frame.
    /// @return True when this scene has to stay. False when the next scene has to be inited.
    virtual bool step
    (
        Renderer &r_renderer,
        Controls &r_controls,
        Controls &r_old_controls
    ) = 0;

    /// @brief Render all the contents of this scene.
    /// @param r_renderer Access the Renderer object to render stuff.
    virtual void render(Renderer &r_renderer) = 0;

    /// @brief Get info about which scene is asked to be inited after this one.
    ///
    /// Call it when `step()` returned false.
    /// @return Struct telling which scene is asked to be inited
    /// and if this one should retain context.
    NextScene getNext() { return IScene::m_NextScene; };

    /// @brief Tell whether game has to be closed now due to the action inside a scene.
    /// @return True if game has to be closed now.
    bool getExit() { return IScene::m_IsExit; };

protected:
    /// @brief Struct containing info about the next scene.
    ///
    /// Should be defined before returning false in `step()`.
    NextScene m_NextScene;

    /// @brief Boolean telling if the game has to be closed now due to the action inside a scene.
    ///
    /// Should be defined before returning false in `step()`.
    bool m_IsExit = false;
};
