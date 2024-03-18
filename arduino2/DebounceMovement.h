#pragma once
#include "MedReminderStateMachine.h"

class DebounceMovement : public BaseDebounceMovement {
public:
    DebounceMovement(MedReminderStateMachine* machine) : BaseDebounceMovement(machine) {}

};