#pragma once
#include "MedReminderStateMachine.h"

class CountMovement : public BaseCountMovement {
public:
    CountMovement(MedReminderStateMachine* machine) : BaseCountMovement(machine) {}

};