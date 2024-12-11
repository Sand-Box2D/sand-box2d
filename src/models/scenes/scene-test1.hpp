/// @brief This provides an implementation of a scene, `SceneTestOne`.

#pragma once

#include <vector> // IWYU pragma: export

#include "scene.hpp"

#include "platform/imgui-manager/imgui-manager.hpp" // IWYU pragma: export

/**
 * @brief test1.
 */
class SceneTestOne : public IScene
{
public:
    SceneTestOne();
    ~SceneTestOne();

    virtual void init() override;
    virtual void free() override;
    virtual bool step
    (
        Renderer &r_renderer,
        Controls &r_controls,
        Controls &r_old_controls
    ) override;
    virtual void render(Renderer &r_renderer) override;

private:
    /// @brief TODO: DELETE ME.
    bool m_TestDirection;
    /// @brief TODO: DELETE ME.
    const unsigned char m_TestMin = 0x30;
    /// @brief TODO: DELETE ME.
    const unsigned char m_TestMax = 0x50;
    /// @brief TODO: DELETE ME.
    const unsigned char m_TestSpeed = 0x20;
    /// @brief TODO: DELETE ME.
    float m_Test;
    /// @brief TODO: DELETE ME.
    bool just_inited = true;
};
