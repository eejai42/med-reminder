#pragma once
#include "MedReminderStateMachine.h"

class GatherReminders : public BaseGatherReminders {
public:
    GatherReminders(MedReminderStateMachine* machine) : BaseGatherReminders(machine) {}

};