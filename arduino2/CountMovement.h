#pragma once
#include "MedReminderStateMachine.h"

class CountMovement : public BaseCountMovement {
public:
    CountMovement(MedReminderStateMachine* machine) : BaseCountMovement(machine) {}

    bool hasMovementCounted() override {
        // Transition logic for MovementCounted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};