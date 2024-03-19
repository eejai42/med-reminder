#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseSaveReminders.h" // Ensure base class is included if separate

class SaveReminders : public BaseSaveReminders {
public:
    using BaseSaveReminders::BaseSaveReminders;
    SaveReminders(MedReminderStateMachine* machine);

    bool hasRemindersSaved() override;
};