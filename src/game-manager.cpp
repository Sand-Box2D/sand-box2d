#include "game-manager.hpp"

GameManager::GameManager() {}
GameManager::~GameManager() {}

// FIXME: Delete all this s*** when needed
bool test_direction = true;
const unsigned char test_min = 0x30;
const unsigned char test_max = 0x50;
unsigned char test = test_min;
//////////////////////////////////////////

bool GameManager::step()
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

void GameManager::render()
{
    // render...
    GameManager::m_Renderer.clearScreen({0x40, 0x40, test});

    GameManager::m_Renderer.render();
}
