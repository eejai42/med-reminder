#pragma once
#include "Idle.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    Idle::Idle(BaseStateMachine* machine) : BaseIdle(machine) {
        // Constructor implementation, if needed
    }

    bool Idle::hasReminderTimeReached() {
        // Determine if ReminderTimeReached
        return false; // assume this has not yet happened
    }
    bool Idle::hasWheelMoved() {
        // Determine if WheelMoved
        return false; // assume this has not yet happened
    }