#pragma once
#include "MedReminderStateMachine.h"

class Idle : public BaseIdle {
public:
    Idle(MedReminderStateMachine* machine) : BaseIdle(machine) {}

};