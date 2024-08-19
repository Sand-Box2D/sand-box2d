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
    GameManager::m_Renderer.init({1, RR_MODE_WINDOW, 960, 544});

    while (GameManager::m_step())
        GameManager::m_render();
}

// FIXME: Delete all this s*** when needed
bool test_direction = true;
const unsigned char test_min = 0x30;
const unsigned char test_max = 0x50;
unsigned char test = test_min;
//////////////////////////////////////////

bool GameManager::m_step()
{
    GameManager::m_Controls.check();

    // step...
    if ((test > test_max) || (test < test_min))
        test_direction = !test_direction;
    if (test_direction)
        test++;
    else
        test--;

    GameManager::m_OldControls = GameManager::m_Controls;

    return !GameManager::m_Controls.getQuit();
}

void GameManager::m_render()
{
    // render...
    GameManager::m_Renderer.clearScreen({0x40, 0x40, test});

    GameManager::m_Renderer.render();
}
