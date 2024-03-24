#pragma once
#include "Alerting.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    Alerting::Alerting(BaseStateMachine* machine) : BaseAlerting(machine) {
        // Constructor implementation, if needed
    }

    bool Alerting::hasSystemButtonPushed() {
        // Determine if SystemButtonPushed
        return false; // assume this has not yet happened
    }
    bool Alerting::hasMovementDetected() {
        // Determine if MovementDetected
        return false; // assume this has not yet happened
    }