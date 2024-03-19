#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseDebounceMovement.h" // Ensure base class is included if separate

class DebounceMovement : public BaseDebounceMovement {
public:
    using BaseDebounceMovement::BaseDebounceMovement;
    DebounceMovement(MedReminderStateMachine* machine);

    virtual void onCheck() override; // called in the arduio loop

    virtual void onEnter() override; // called when the state is activated
    virtual void onExit() override; // called when the state is de-activated

    bool hasReminderDebounceFailed() override;
    bool hasDebounceFailed() override;
    bool hasDebouncePassed() override;
};