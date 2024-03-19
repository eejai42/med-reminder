#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseDebounceMovement.h" // Ensure base class is included if separate

class DebounceMovement : public BaseDebounceMovement {
public:
    using BaseDebounceMovement::BaseDebounceMovement;
    DebounceMovement(MedReminderStateMachine* machine);

    bool hasReminderDebounceFailed() override;
    bool hasDebounceFailed() override;
    bool hasDebouncePassed() override;
};