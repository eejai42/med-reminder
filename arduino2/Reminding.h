#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseReminding.h" // Ensure base class is included if separate

class Reminding : public BaseReminding {
public:
    using BaseReminding::BaseReminding;
    Reminding(MedReminderStateMachine* machine);

    bool hasWheelMoved() override;
};