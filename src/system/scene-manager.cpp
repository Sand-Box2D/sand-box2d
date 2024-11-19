#include "scene-manager.hpp"

// TODO: THERE ARE FREAKING 5 SWITCHES IN THIS FILE
// Please, remove this boilerplate s***.

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

void SceneManager::init(CurrentScene scene_to_init)
{
    SceneManager::m_CurrentScene = scene_to_init;

    switch (SceneManager::m_CurrentScene)
    {
    case SCENE_MAIN:
        SceneManager::m_SceneMain.init();
        break;
    case SCENE_TEST_ONE:
        SceneManager::m_SceneTestOne.init();
        break;
    case SCENE_TEST_TWO:
        SceneManager::m_SceneTestTwo.init();
        break;

    default:
        break;
    }
}

bool SceneManager::step
(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    bool done = false;

    while (!done)
    {
        done = SceneManager::m_ExecuteOneStep(
            SceneManager::m_CurrentScene,
            r_renderer,
            r_controls,
            r_old_controls
        );

        if (!done)
        {
            if (SceneManager::m_GetExitScene(SceneManager::m_CurrentScene))
                return false;

            auto asked_scene = SceneManager::m_GetNextScene(SceneManager::m_CurrentScene).asked_scene;

            SceneManager::init(asked_scene);
        }
        done = true;
    }

    return true;
}

void SceneManager::render(Renderer &r_renderer)
{
    switch (SceneManager::m_CurrentScene)
    {
    case SCENE_MAIN:
        SceneManager::m_SceneMain.render(r_renderer);
        break;
    case SCENE_TEST_ONE:
        SceneManager::m_SceneTestOne.render(r_renderer);
        break;
    case SCENE_TEST_TWO:
        SceneManager::m_SceneTestTwo.render(r_renderer);
        break;

    default:
        break;
    }
    
}

bool SceneManager::m_ExecuteOneStep
(
    CurrentScene scene_to_execute,
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    bool to_return = false;

    switch (scene_to_execute)
    {
    case SCENE_MAIN:
        to_return = SceneManager::m_SceneMain.step(r_renderer, r_controls, r_old_controls);
        break;
    case SCENE_TEST_ONE:
        to_return = SceneManager::m_SceneTestOne.step(r_renderer, r_controls, r_old_controls);
        break;
    case SCENE_TEST_TWO:
        to_return = SceneManager::m_SceneTestTwo.step(r_renderer, r_controls, r_old_controls);
        break;

    default:
        break;
    }

    return to_return;
}

// TODO: smells a lot boilerplate in here...
// there should be a way in c++17 to get rid of it.
bool SceneManager::m_GetExitScene(CurrentScene scene_to_query)
{
    bool to_return = false;

    switch (scene_to_query)
    {
    case SCENE_MAIN:
        to_return = SceneManager::m_SceneMain.getExit();
        break;
    case SCENE_TEST_ONE:
        to_return = SceneManager::m_SceneTestOne.getExit();
        break;
    case SCENE_TEST_TWO:
        to_return = SceneManager::m_SceneTestTwo.getExit();
        break;

    default:
        break;
    }

    return to_return;
}

NextScene SceneManager::m_GetNextScene(CurrentScene scene_to_query) // it makes... 5 scenes per line
{
    NextScene to_return = {};

    switch (scene_to_query)
    {
    case SCENE_MAIN:
        to_return = SceneManager::m_SceneMain.getNext();
        break;
    case SCENE_TEST_ONE:
        to_return = SceneManager::m_SceneTestOne.getNext();
        break;
    case SCENE_TEST_TWO:
        to_return = SceneManager::m_SceneTestTwo.getNext();
        break;

    default:
        break;
    }

    return to_return;
}
