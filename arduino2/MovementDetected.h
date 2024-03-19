#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseMovementDetected.h" // Ensure base class is included if separate

class MovementDetected : public BaseMovementDetected {
public:
    using BaseMovementDetected::BaseMovementDetected;
    MovementDetected(MedReminderStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasMovementHandled() override;
};