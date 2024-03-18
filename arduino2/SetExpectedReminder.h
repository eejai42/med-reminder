#pragma once
#include "MedReminderStateMachine.h"

class SetExpectedReminder : public BaseSetExpectedReminder {
public:
    SetExpectedReminder(MedReminderStateMachine* machine) : BaseSetExpectedReminder(machine) {}

};