#include "main.hpp"

int main()
{
    auto renderer = Renderer();

    renderer.init();

    for (int i = 0; i < 1000; i++)  // A cheap way to close the game
    {
        renderer.clearScreen({0, 0, 0xFF});
        renderer.render();
    }
}
