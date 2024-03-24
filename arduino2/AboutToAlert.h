#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseAboutToAlert.h" // Ensure base class is included if separate

class AboutToAlert : public BaseAboutToAlert {
public:
    using BaseAboutToAlert::BaseAboutToAlert;
    AboutToAlert(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasReminderTimeReached() override;
    bool hasMovementDetected() override;
};