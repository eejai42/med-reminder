#pragma once
#include "CountMovement.h"
#include <iostream> // Include if you use std::cout or similar in implementations

    CountMovement::CountMovement(BaseStateMachine* machine) : BaseCountMovement(machine) {
        // Constructor implementation, if needed
    }

    bool CountMovement::hasMovementCounted() {
        // Determine if MovementCounted
        return false; // assume this has not yet happened
    }