#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseReminding.h" // Ensure base class is included if separate

class Reminding : public BaseReminding {
public:
    using BaseReminding::BaseReminding;
    Reminding(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasWheelMoved() override;
};