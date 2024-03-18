#pragma once
#include "MedReminderStateMachine.h"

class AdvanceCurrentReminder : public BaseAdvanceCurrentReminder {
public:
    AdvanceCurrentReminder(MedReminderStateMachine* machine) : BaseAdvanceCurrentReminder(machine) {}

};