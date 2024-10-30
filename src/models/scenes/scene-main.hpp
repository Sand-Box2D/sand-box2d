/// @brief This provides an implementation of a scene, `SceneMain`.

#pragma once

#include "scene.hpp"

#include "platform/imgui-manager/imgui-manager.hpp"

/**
 * @brief Main Menu Scene.
 * 
 * Shows the main menu where you can select other game scenes
 * and also "play with our logo".
 */
class SceneMain : public IScene
{
public:
    SceneMain();
    ~SceneMain();

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
    const unsigned char m_TestMin;
    /// @brief TODO: DELETE ME.
    const unsigned char m_TestMax;
    /// @brief TODO: DELETE ME.
    const unsigned char m_TestSpeed;
    /// @brief TODO: DELETE ME.
    unsigned char m_Test;
};
