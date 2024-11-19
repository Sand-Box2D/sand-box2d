#include "scene-main.hpp"

SceneMain::SceneMain() {}
SceneMain::~SceneMain()
{
    SceneMain::free();
}

void SceneMain::init()
{
    SceneMain::free();

    SceneMain::m_TestDirection = true;
    SceneMain::m_Test = (float) m_TestMin;

    SceneMain::just_inited = true;
}

void SceneMain::free() {}

bool SceneMain::step(
    Renderer &r_renderer,
    Controls &r_controls,
    Controls &r_old_controls
) {
    if (!r_controls.getMenuRight() && r_old_controls.getMenuRight() && !just_inited)
    {
        SceneMain::m_NextScene = { SCENE_TEST_ONE, false };
        return false;
    }
    if (!r_controls.getMenuLeft() && r_old_controls.getMenuLeft() && !just_inited)
    {
        SceneMain::m_NextScene = { SCENE_TEST_TWO, false };
        return false;
    }

    float testStep = SceneMain::m_TestSpeed * r_renderer.getDelta() / 1000.f;

    if ((unsigned char) SceneMain::m_Test > SceneMain::m_TestMax)
        SceneMain::m_TestDirection = false;
    if ((unsigned char) SceneMain::m_Test < SceneMain::m_TestMin)
        SceneMain::m_TestDirection = true;

    if (SceneMain::m_TestDirection)
        SceneMain::m_Test += testStep;
    else
        SceneMain::m_Test -= testStep;

    SceneMain::m_TestValues.push_back(SceneMain::m_Test);
    SceneMain::m_TestDirectionValues.push_back(SceneMain::m_TestDirection ? 1 : 0);

    if (SceneMain::m_TestValues.size() > SceneMain::m_TestMaxValues)
    {
        SceneMain::m_TestValues.erase(SceneMain::m_TestValues.begin());
        SceneMain::m_TestDirectionValues.erase(SceneMain::m_TestDirectionValues.begin());
    }

    ImGui::ShowDemoWindow();

    ImGui::Begin("Debug");

    ImGui::Text("SceneMain::m_TestSpeed = %d", SceneMain::m_TestSpeed);
    ImGui::Text("testStep = %f", testStep);
    ImGui::Text("frameRate = %d FPS", (int)(1.f / (r_renderer.getDelta() / 1000.f)));
    ImGui::Text("SceneMain::m_TestDirection = %d", SceneMain::m_TestDirection);
    ImGui::Text("SceneMain::m_Test = %f", SceneMain::m_Test);
    ImGui::PlotLines(
        "m_Test",
        SceneMain::m_TestValues.data(),
        SceneMain::m_TestValues.size()
    );
    ImGui::PlotLines(
        "m_TestDirection",
        SceneMain::m_TestDirectionValues.data(),
        SceneMain::m_TestDirectionValues.size()
    );

    ImGui::Separator();

    ImGui::Text("r_controls.getMenuUp() = %d", r_controls.getMenuUp());
    ImGui::Text("r_controls.getMenuDown() = %d", r_controls.getMenuDown());
    ImGui::Text("r_controls.getMenuLeft() = %d", r_controls.getMenuLeft());
    ImGui::Text("r_controls.getMenuRight() = %d", r_controls.getMenuRight());

    ImGui::Separator();

    ImGui::Text("Cliclking MenuLeft and MenuRight will switch between 3 scenes.");

    ImGui::End();

    SceneMain::just_inited = false;

    return true;
}

void SceneMain::render(Renderer &r_renderer)
{
    r_renderer.clearScreen({0x40, 0x40, (unsigned char) SceneMain::m_Test});
}
