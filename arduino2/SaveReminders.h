#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseSaveReminders.h" // Ensure base class is included if separate

class SaveReminders : public BaseSaveReminders {
public:
    using BaseSaveReminders::BaseSaveReminders;
    SaveReminders(MedReminderStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasRemindersSaved() override;
};