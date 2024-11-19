#include "game-manager.hpp"

GameManager::GameManager(std::string pathToSettings, std::string pathToDefSettings)
{
    GameManager::m_SceneManager.init(SCENE_MAIN);

    GameManager::m_Settings.init(pathToSettings, pathToDefSettings);

    const float scale = 1;

    GameManager::m_Renderer.init({
        scale,
        GameManager::m_Settings.get("screen-mode").asString() == "window"
            ? RR_MODE_WINDOW
            : RR_MODE_FULLSCREEN_SOFT,
        GameManager::m_Settings.get("screen-width").asInt(),
        GameManager::m_Settings.get("screen-height").asInt(),
    });

    GameManager::m_ImGuiManager.init(GameManager::m_Renderer);
}
GameManager::~GameManager() {}

bool GameManager::step()
{
    GameManager::m_Controls.check();

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
    GameManager::m_SceneManager.render(GameManager::m_Renderer);

    GameManager::m_ImGuiManager.render(GameManager::m_Renderer);

    GameManager::m_Renderer.render();
}
