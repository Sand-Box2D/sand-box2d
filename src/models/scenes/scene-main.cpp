#include "scene-main.hpp"

SceneMain::SceneMain()
    : m_TestMin(0x30)       // First time using RAII syntax, yay!@!1!
    , m_TestSpeed(0x40)
    , m_TestMax(0x50)
{}
SceneMain::~SceneMain()
{
    SceneMain::free();
}

void SceneMain::init()
{
    SceneMain::free();

    SceneMain::m_TestDirection = true;
    SceneMain::m_Test = m_TestMin;
}

void SceneMain::free() {}

bool SceneMain::step(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    float testStep = SceneMain::m_TestSpeed * r_renderer.getDelta() / 1000.f;

    if (SceneMain::m_Test > SceneMain::m_TestMax)
        SceneMain::m_TestDirection = false;
    if (SceneMain::m_Test < SceneMain::m_TestMin)
        SceneMain::m_TestDirection = true;

    if (SceneMain::m_TestDirection)
        SceneMain::m_Test += testStep;
    else
        SceneMain::m_Test -= testStep;

    return true;
}

void SceneMain::render(Renderer &r_renderer)
{
    r_renderer.clearScreen({0x40, 0x40, SceneMain::m_Test});
}
