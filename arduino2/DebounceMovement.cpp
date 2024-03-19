#pragma once
#include "DebounceMovement.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    DebounceMovement::DebounceMovement(BaseStateMachine* machine) : BaseDebounceMovement(machine) {
        // Constructor implementation, if needed
    }

    bool DebounceMovement::hasReminderDebounceFailed() {
        // Determine if ReminderDebounceFailed
        return false; // assume this has not yet happened
    }
    bool DebounceMovement::hasDebounceFailed() {
        // Determine if DebounceFailed
        return false; // assume this has not yet happened
    }
    bool DebounceMovement::hasDebouncePassed() {
        // Determine if DebouncePassed
        return false; // assume this has not yet happened
    }