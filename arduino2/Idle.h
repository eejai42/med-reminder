#pragma once
#include "MedReminderStateMachine.h"

class Idle : public BaseIdle {
public:
    Idle(MedReminderStateMachine* machine) : BaseIdle(machine) {}

    bool hasWheelMoved() override {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    bool hasMainInputClicked() override {
        // Transition logic for MainInputClicked
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};