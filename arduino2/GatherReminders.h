#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseGatherReminders.h" // Ensure base class is included if separate

class GatherReminders : public BaseGatherReminders {
public:
    using BaseGatherReminders::BaseGatherReminders;
    GatherReminders(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasGatheringRemindersCompleted() override;
};