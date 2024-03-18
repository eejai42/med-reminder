#pragma once
#include "MedReminderStateMachine.h"

class Reboot : public BaseReboot {
public:
    Reboot(MedReminderStateMachine* machine) : BaseReboot(machine) {}

};