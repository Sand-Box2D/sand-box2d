#include "main.hpp"

int main()
{
    auto renderer = Renderer();

    renderer.init({1, RR_MODE_WINDOW, 1920/2, 1080/2});

    for (int i = 0; i < 2000; i++)  // A cheap way to close the game
    {
        renderer.clearScreen({0, 0, 0xFF});
        renderer.render();
    }
}
