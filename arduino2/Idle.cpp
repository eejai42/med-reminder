#pragma once
#include "MedReminderStateMachine.h"

int ms = 0;
void MedReminderStateMachine::enterIdle() {
    // Actions to perform on entering Idle
}

void MedReminderStateMachine::exitIdle() {
    // Actions to perform on exiting Idle
}

bool MedReminderStateMachine::hasIdle_WithinMSOfNextReminder() {
    // Determine if WithinMSOfNextReminder
    if (ms++ == 100) return true;
    else return false; // assume this has not yet happened
}