#include "main.hpp"

int main()
{
    auto renderer = Renderer();
    auto ctrl = Controls();

    renderer.init({1, RR_MODE_WINDOW, 960, 544});

    do
    {
        ctrl.check();

        renderer.clearScreen({0x40, 0x40, 0x40});
        renderer.render();
    } while (!ctrl.getQuit());
}
