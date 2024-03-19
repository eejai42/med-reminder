#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseGatherReminders.h" // Ensure base class is included if separate

class GatherReminders : public BaseGatherReminders {
public:
    using BaseGatherReminders::BaseGatherReminders;
    GatherReminders(MedReminderStateMachine* machine);

    bool hasGatheringRemindersCompleted() override;
};