#pragma once
#include "MedReminderStateMachine.h"

class Idle : public BaseIdle {
public:
    Idle(MedReminderStateMachine* machine) : BaseIdle(machine) {}

    bool hasReminderTimeReached() override {
        // Transition logic for ReminderTimeReached
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    bool hasWheelMoved() override {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};