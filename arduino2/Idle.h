#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseIdle.h" // Ensure base class is included if separate

class Idle : public BaseIdle {
public:
    using BaseIdle::BaseIdle;
    Idle(MedReminderStateMachine* machine);

    bool hasReminderTimeReached() override;
    bool hasWheelMoved() override;
};