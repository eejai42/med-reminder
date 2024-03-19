#pragma once
#include "MedReminderStateMachine.h"
// #include "BaseBootup.h" // Ensure base class is included if separate

class Bootup : public BaseBootup {
public:
    using BaseBootup::BaseBootup;
    Bootup(MedReminderStateMachine* machine);

    bool hasBootupCompleted() override;
};