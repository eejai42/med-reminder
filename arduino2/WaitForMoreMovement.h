#pragma once
#include "MedReminderStateMachine.h"

class WaitForMoreMovement : public BaseWaitForMoreMovement {
public:
    WaitForMoreMovement(MedReminderStateMachine* machine) : BaseWaitForMoreMovement(machine) {}

    bool hasWheelMoved() override {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    bool hasWheelNotMoved() override {
        // Transition logic for WheelNotMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};