#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseCountMovement.h" // Ensure base class is included if separate

class CountMovement : public BaseCountMovement {
public:
    using BaseCountMovement::BaseCountMovement;
    CountMovement(MedReminderStateMachine* machine);

    bool hasMovementCounted() override;
};