#pragma once
#include "MedReminderStateMachine.h"

class WaitForMoreMovement : public BaseWaitForMoreMovement {
public:
    WaitForMoreMovement(MedReminderStateMachine* machine) : BaseWaitForMoreMovement(machine) {}

};