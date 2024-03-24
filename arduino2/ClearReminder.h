#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseClearReminder.h" // Ensure base class is included if separate

class ClearReminder : public BaseClearReminder {
public:
    using BaseClearReminder::BaseClearReminder;
    ClearReminder(BaseStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasReminderCleared() override;
};