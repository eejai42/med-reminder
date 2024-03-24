#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseTrainingMovement.h" // Ensure base class is included if separate

class TrainingMovement : public BaseTrainingMovement {
public:
    using BaseTrainingMovement::BaseTrainingMovement;
    TrainingMovement(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasReminderSaved() override;
};