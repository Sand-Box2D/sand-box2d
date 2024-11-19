#include "main.hpp"

int main()
{
    GameManager game_manager(PATH_TO_SETTINGS, PATH_TO_DEF_SETTINGS);

    while(game_manager.step())
        game_manager.render();
}
