#pragma once
#include "MedReminderStateMachine.h"

class Reboot : public BaseReboot {
public:
    Reboot(MedReminderStateMachine* machine) : BaseReboot(machine) {}

    bool hasRebootStarted() override {
        // Transition logic for RebootStarted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};