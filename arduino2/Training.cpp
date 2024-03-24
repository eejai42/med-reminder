#pragma once
#include "Training.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    Training::Training(BaseStateMachine* machine) : BaseTraining(machine) {
        // Constructor implementation, if needed
    }

    bool Training::hasMovementDetected() {
        // Determine if MovementDetected
        return false; // assume this has not yet happened
    }
    bool Training::hasNewDay() {
        // Determine if NewDay
        return false; // assume this has not yet happened
    }