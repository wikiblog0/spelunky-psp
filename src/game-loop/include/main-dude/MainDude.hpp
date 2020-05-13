#pragma once

#include "RenderEntity.hpp"
#include "GameObject.hpp"
#include "components/PhysicsComponent.hpp"
#include "components/QuadComponent.hpp"
#include "components/InputComponent.hpp"
#include "components/AnimationComponent.hpp"

#include "MainDudeSpritesheetFrames.hpp"
#include "main-dude/states/MainDudeRunning.hpp"
#include "main-dude/states/MainDudeStanding.hpp"

#include <vector>

class MainDudeBaseState;
class MainDude : public GameObject
{
public:

    MainDude();
    void update(uint32_t delta_time_ms) override;

private:

    friend class PhysicsComponent;
    friend class QuadComponent;
    friend class InputComponent;
    friend class AnimationComponent;
    PhysicsComponent _physics;
    QuadComponent _quad;
    InputComponent _input;
    AnimationComponent _animation;

    friend class MainDudeBaseState;
    friend class MainDudeRunning;
    friend class MainDudeStanding;
    struct
    {
        MainDudeBaseState* current = nullptr;
        MainDudeRunning running;
        MainDudeStanding standing;
    } _states;

    struct
    {
        bool facing_left;
    } _other;
};