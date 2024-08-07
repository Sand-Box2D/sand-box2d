#include "main.hpp"

int main()
{
    auto renderer = Renderer();

    renderer.init();

    return 0;   // I mean, it's cool if you can compile.
                // But please, don't launch the loop.

    while (true)
    {
        renderer.clearScreen({0, 0, 0xFF});
        renderer.render();
    }
}
