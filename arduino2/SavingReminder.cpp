#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasSavingReminder_ReminderSaved() {
    // Check condition for ReminderSaved in SavingReminder state
    reminders++;
    Serial.println("REMINDER Time Saved!");
    return true;
}