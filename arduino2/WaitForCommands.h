#pragma once
#include "MedReminderStateMachine.h"

class WaitForCommands : public BaseWaitForCommands {
public:
    WaitForCommands(MedReminderStateMachine* machine) : BaseWaitForCommands(machine) {}

};