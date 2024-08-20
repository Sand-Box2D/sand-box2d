#include "main.hpp"

int main()
{
    GameManager game_manager;

    while(game_manager.step())
        game_manager.render();
}
