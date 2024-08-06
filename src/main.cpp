#include "main.hpp"

int main()
{
    std::unique_ptr<BaseRenderer> renderer = std::make_unique<RendererSdl2>();

    renderer->init();

    while (true)
    {
        renderer->clearScreen({0x10, 0x10, 0x10});
        renderer->render();
    }
}
