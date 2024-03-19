#pragma once
#include "MedReminderStateMachine.h"

class Reminding : public BaseReminding {
public:
    Reminding(MedReminderStateMachine* machine) : BaseReminding(machine) {}

    bool hasWheelMoved() override {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};