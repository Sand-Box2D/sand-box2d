#pragma once

/**
 * @brief Base class for a scene,
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
 */

enum Scene
{
    SCENE_MAIN = 0
};

class BaseScene
{
public:
    virtual ~BaseScene() {};
protected:
    /* data */
};
