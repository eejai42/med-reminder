#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseAlerting.h" // Ensure base class is included if separate

class Alerting : public BaseAlerting {
public:
    using BaseAlerting::BaseAlerting;
    Alerting(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasSystemButtonPushed() override;
    bool hasMovementDetected() override;
};