#pragma once
#include "MedReminderStateMachine.h"

class DebounceMovement : public BaseDebounceMovement {
public:
    DebounceMovement(MedReminderStateMachine* machine) : BaseDebounceMovement(machine) {}

    bool hasDebouncePassed() override {
        // Transition logic for DebouncePassed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    bool hasDebounceFailed() override {
        // Transition logic for DebounceFailed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};