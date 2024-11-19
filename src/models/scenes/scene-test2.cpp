#include "scene-test2.hpp"

SceneTestTwo::SceneTestTwo() {}
SceneTestTwo::~SceneTestTwo()
{
    SceneTestTwo::free();
}

void SceneTestTwo::init()
{
    SceneTestTwo::free();

    SceneTestTwo::m_TestDirection = true;
    SceneTestTwo::m_Test = (float) m_TestMin;

    SceneTestTwo::just_inited = true;
}

void SceneTestTwo::free() {}

bool SceneTestTwo::step(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    if (!r_controls.getMenuRight() && r_old_controls.getMenuRight() && !just_inited)
    {
        SceneTestTwo::m_NextScene = { SCENE_MAIN, false };
        return false;
    }
    if (!r_controls.getMenuLeft() && r_old_controls.getMenuLeft() && !just_inited)
    {
        SceneTestTwo::m_NextScene = { SCENE_TEST_ONE, false };
        return false;
    }

    float testStep = SceneTestTwo::m_TestSpeed * r_renderer.getDelta() / 1000.f;

    if ((unsigned char) SceneTestTwo::m_Test > SceneTestTwo::m_TestMax)
        SceneTestTwo::m_TestDirection = false;
    if ((unsigned char) SceneTestTwo::m_Test < SceneTestTwo::m_TestMin)
        SceneTestTwo::m_TestDirection = true;

    if (SceneTestTwo::m_TestDirection)
        SceneTestTwo::m_Test += testStep;
    else
        SceneTestTwo::m_Test -= testStep;

    ImGui::ShowDemoWindow();

    ImGui::Begin("Debug2");

    ImGui::Text("frameRate = %d FPS", (int)(1.f / (r_renderer.getDelta() / 1000.f)));
    ImGui::Text("SceneTestTwo::m_TestDirection = %d", SceneTestTwo::m_TestDirection);
    ImGui::Text("SceneTestTwo::m_Test = %f", SceneTestTwo::m_Test);

    ImGui::Separator();

    ImGui::Text("r_controls.getMenuUp() = %d", r_controls.getMenuUp());
    ImGui::Text("r_controls.getMenuDown() = %d", r_controls.getMenuDown());
    ImGui::Text("r_controls.getMenuLeft() = %d", r_controls.getMenuLeft());
    ImGui::Text("r_controls.getMenuRight() = %d", r_controls.getMenuRight());

    ImGui::Separator();

    ImGui::Text("Cliclking MenuLeft and MenuRight will switch between 3 scenes.");

    ImGui::End();

    SceneTestTwo::just_inited = false;

    return true;
}

void SceneTestTwo::render(Renderer &r_renderer)
{
    r_renderer.clearScreen({(unsigned char) SceneTestTwo::m_Test, 0x40, 0x40});
}
