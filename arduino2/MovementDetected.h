#pragma once
#include "MedReminderStateMachine.h"

class MovementDetected : public BaseMovementDetected {
public:
    MovementDetected(MedReminderStateMachine* machine) : BaseMovementDetected(machine) {}

};