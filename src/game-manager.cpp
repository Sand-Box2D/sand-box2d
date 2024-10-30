#include "game-manager.hpp"

GameManager::GameManager()
{
    // load settings...
    GameManager::m_SceneManager.init(SCENE_MAIN);

    GameManager::m_Renderer.init({1, RR_MODE_WINDOW, 960, 544});
    GameManager::m_ImGuiManager.init(GameManager::m_Renderer);
}
GameManager::~GameManager() {}

bool GameManager::step()
{
    GameManager::m_Controls.check();

    // step...
    GameManager::m_ImGuiManager.step();

    GameManager::m_SceneManager.step(
        GameManager::m_Renderer,
        GameManager::m_Controls,
        GameManager::m_OldControls
    );

    GameManager::m_OldControls = GameManager::m_Controls;

    return !GameManager::m_Controls.getQuit();
}

void GameManager::render()
{
    // render...
    GameManager::m_SceneManager.render(GameManager::m_Renderer);
    GameManager::m_ImGuiManager.render(GameManager::m_Renderer);

    GameManager::m_Renderer.render();
}
