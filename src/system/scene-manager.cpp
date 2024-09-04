#include "scene-manager.hpp"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

void SceneManager::init(CurrentScene scene_to_init)
{
    SceneManager::m_SceneMain.init();
}

bool SceneManager::step
(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
)
{
    SceneManager::m_SceneMain.step(r_renderer, r_controls, r_old_controls);
    return true;
}

void SceneManager::render(Renderer &r_renderer)
{
    SceneManager::m_SceneMain.render(r_renderer);
}
