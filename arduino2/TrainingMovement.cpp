#pragma once
#include "TrainingMovement.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    TrainingMovement::TrainingMovement(BaseStateMachine* machine) : BaseTrainingMovement(machine) {
        // Constructor implementation, if needed
    }

    bool TrainingMovement::hasReminderSaved() {
        // Determine if ReminderSaved
        return false; // assume this has not yet happened
    }