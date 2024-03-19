#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseWaitForMoreMovement.h" // Ensure base class is included if separate

class WaitForMoreMovement : public BaseWaitForMoreMovement {
public:
    using BaseWaitForMoreMovement::BaseWaitForMoreMovement;
    WaitForMoreMovement(MedReminderStateMachine* machine);

    bool hasWheelMoved() override;
    bool hasWheelNotMoved() override;
};