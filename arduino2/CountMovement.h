#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseCountMovement.h" // Ensure base class is included if separate

class CountMovement : public BaseCountMovement {
public:
    using BaseCountMovement::BaseCountMovement;
    CountMovement(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasMovementCounted() override;
};