#include "game-manager.hpp"

GameManager::GameManager()
{
    GameManager::m_Renderer = Renderer();

    GameManager::m_Controls = Controls();
    GameManager::m_OldControls = Controls();
}
GameManager::~GameManager() {}

void GameManager::cycle()
{
    bool is_running = true;

    GameManager::m_Renderer.init({1, RR_MODE_WINDOW, 960, 544});

    while (is_running)
    {
        is_running = GameManager::m_step();
        GameManager::m_render();
    }
}

bool GameManager::m_step()
{
    GameManager::m_Controls.check();

    // step...

    GameManager::m_OldControls = GameManager::m_Controls;

    return !GameManager::m_Controls.getQuit();
}

void GameManager::m_render()
{
    GameManager::m_Renderer.clearScreen({0x40, 0x40, 0x40});

    // render...

    GameManager::m_Renderer.render();
}
