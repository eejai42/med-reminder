#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseTraining.h" // Ensure base class is included if separate

class Training : public BaseTraining {
public:
    using BaseTraining::BaseTraining;
    Training(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasMovementDetected() override;
    bool hasNewDay() override;
};