#pragma once
#include "MedReminderStateMachine.h"

void MedReminderStateMachine::enterSavingReminder() {
    // Actions to perform on entering SavingReminder
    Serial.println("SAVING REMINDER");
    reminders++;
}

bool MedReminderStateMachine::hasSavingReminder_ReminderSaved() {
    // Check condition for ReminderSaved in SavingReminder state
    return true;
}