#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasSavingReminder_ReminderSaved() {
    // Check condition for ReminderSaved in SavingReminder state
    reminders++;

    if (reminders < maxReminders) {
      Serial.println("Saving reminder at: " + String(dailyMillis));
      reminderTimes[reminders] = dailyMillis;
      reminders++;        
      return true;
    }
    return true;
}

void MedReminderStateMachine::enterSavingReminder() {
    // Actions to perform on entering SavingReminder
}
 
void MedReminderStateMachine::exitSavingReminder() {
    // Actions to perform on entering SavingReminder
}
 