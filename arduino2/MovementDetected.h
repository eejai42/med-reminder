#pragma once
#include "MedReminderStateMachine.h"

class MovementDetected : public BaseMovementDetected {
public:
    MovementDetected(MedReminderStateMachine* machine) : BaseMovementDetected(machine) {}

    bool hasMovementHandled() override {
        // Transition logic for MovementHandled
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};