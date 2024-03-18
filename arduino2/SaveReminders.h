#pragma once
#include "MedReminderStateMachine.h"

class SaveReminders : public BaseSaveReminders {
public:
    SaveReminders(MedReminderStateMachine* machine) : BaseSaveReminders(machine) {}

};