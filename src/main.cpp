#include "main.hpp"

int main()
{
    auto renderer = Renderer();

    return 0;   // I mean, it's cool if you can compile.
                // But please, don't launch me.

    renderer.init();

    while (true)
    {
        renderer.clearScreen({0x10, 0x10, 0x10});
        renderer.render();
    }
}
