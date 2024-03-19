#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseBootup.h" // Ensure base class is included if separate

class Bootup : public BaseBootup {
public:
    using BaseBootup::BaseBootup;
    Bootup(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasBootupCompleted() override;
};