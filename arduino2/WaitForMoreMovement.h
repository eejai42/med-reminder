#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseWaitForMoreMovement.h" // Ensure base class is included if separate

class WaitForMoreMovement : public BaseWaitForMoreMovement {
public:
    using BaseWaitForMoreMovement::BaseWaitForMoreMovement;
    WaitForMoreMovement(MedReminderStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasWheelMoved() override;
    bool hasWheelNotMoved() override;
};