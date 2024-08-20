/// @brief This provides the interface of a scene, `IScene`.

#pragma once

enum Scene
{
    SCENE_MAIN = 0
};

/**
 * @brief Interface for a scene,
 * an object that possesses all the screen area at this moment.
 * 
 * Is managed by SceneManager. When game has to change the scene
 * (like from SceneMain to SceneSettings), SceneManager does the following:
 * 1. First, we should say that there are 3 actions a scene can do: init, step & render.
 * 2. SceneManager has to decide which scene needs to be inited.
 * 2. SceneManager executes "step" on that scene.
 * 3. If scene returns true, SceneManager will render the same scene later
 * and redo the step for it.
 * 4. If false returned, SceneManager will decide which scene should be the next
 * by querying the closing scene (like SceneMain tells us to open SceneSettings).
 * 5. Then, it will init it and rerun the check which window should execute "step".
 * 6. After doing so it will eventually render the new scene.
 * 
 * Notice how SManager didn't render scene when it returned false.
 * We can do a little schema (0Step is one scene, 1Step is another):
 * 
 * 0Step (true) -> 0Render -> 0Step (false) -> 1Init -> 1Step (true) -> 1Render -> 1Step...
 * 
 * Generally, the idea is that there is only one single IScene object
 * which is created and deleted when the scene has to change.
 * 
 * But it's also previewed that there should be an "overlay scene", that is
 * a scene which can render while another scene is still loaded and has all the context
 * with the ability to quickly "resume" it from that state.
 * Imagine settings menu called from pause menu while level is loaded
 * and you can quickly return to it.
 */
class IScene
{
public:
    virtual ~IScene() {};
protected:
    /* data */
};
