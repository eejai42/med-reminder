#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseMovementDetected.h" // Ensure base class is included if separate

class MovementDetected : public BaseMovementDetected {
public:
    using BaseMovementDetected::BaseMovementDetected;
    MovementDetected(MedReminderStateMachine* machine);

    bool hasMovementHandled() override;
};