#include "scene-test1.hpp"

SceneTestOne::SceneTestOne() {}
SceneTestOne::~SceneTestOne()
{
    SceneTestOne::free();
}

void SceneTestOne::init()
{
    SceneTestOne::free();

    SceneTestOne::m_TestDirection = true;
    SceneTestOne::m_Test = (float) m_TestMin;

    SceneTestOne::just_inited = true;
}

void SceneTestOne::free() {}

bool SceneTestOne::step(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    if (!r_controls.getMenuRight() && r_old_controls.getMenuRight() && !just_inited)
    {
        SceneTestOne::m_NextScene = { SCENE_TEST_TWO, false };
        return false;
    }
    if (!r_controls.getMenuLeft() && r_old_controls.getMenuLeft() && !just_inited)
    {
        SceneTestOne::m_NextScene = { SCENE_MAIN, false };
        return false;
    }

    float testStep = SceneTestOne::m_TestSpeed * r_renderer.getDelta() / 1000.f;

    if ((unsigned char) SceneTestOne::m_Test > SceneTestOne::m_TestMax)
        SceneTestOne::m_TestDirection = false;
    if ((unsigned char) SceneTestOne::m_Test < SceneTestOne::m_TestMin)
        SceneTestOne::m_TestDirection = true;

    if (SceneTestOne::m_TestDirection)
        SceneTestOne::m_Test += testStep;
    else
        SceneTestOne::m_Test -= testStep;

    ImGui::ShowDemoWindow();

    ImGui::Begin("Debug1");

    ImGui::Text("SceneTestOne::m_TestSpeed = %d", SceneTestOne::m_TestSpeed);
    ImGui::Text("testStep = %f", testStep);
    ImGui::Text("frameRate = %d FPS", (int)(1.f / (r_renderer.getDelta() / 1000.f)));
    ImGui::Text("SceneTestOne::m_TestDirection = %d", SceneTestOne::m_TestDirection);
    ImGui::Text("SceneTestOne::m_Test = %f", SceneTestOne::m_Test);

    ImGui::Separator();

    ImGui::Text("r_controls.getMenuUp() = %d", r_controls.getMenuUp());
    ImGui::Text("r_controls.getMenuDown() = %d", r_controls.getMenuDown());
    ImGui::Text("r_controls.getMenuLeft() = %d", r_controls.getMenuLeft());
    ImGui::Text("r_controls.getMenuRight() = %d", r_controls.getMenuRight());

    ImGui::Separator();

    ImGui::Text("Cliclking MenuLeft and MenuRight will switch between 3 scenes.");

    ImGui::End();

    SceneTestOne::just_inited = false;

    return true;
}

void SceneTestOne::render(Renderer &r_renderer)
{
    r_renderer.clearScreen({0x40, (unsigned char) SceneTestOne::m_Test, 0x40});
}
