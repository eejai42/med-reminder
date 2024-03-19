#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseIdle.h" // Ensure base class is included if separate

class Idle : public BaseIdle {
public:
    using BaseIdle::BaseIdle;
    Idle(MedReminderStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasReminderTimeReached() override;
    bool hasWheelMoved() override;
};