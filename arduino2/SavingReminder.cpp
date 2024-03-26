#pragma once
#include "MedReminderStateMachine.h"

void MedReminderStateMachine::enterSavingReminder() {
    // Actions to perform on entering SavingReminder
    int reminders = 0;
    Serial.println("SAVING REMINDER");
    reminders++;
}

void MedReminderStateMachine::exitSavingReminder() {
    // Actions to perform on exiting SavingReminder
}

bool MedReminderStateMachine::hasSavingReminder_ReminderSaved() {
    // Check condition for ReminderSaved in SavingReminder state
    return true;
}