#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasSavingReminder_ReminderSaved() {
    // Check condition for ReminderSaved in SavingReminder state
    if (reminders < maxReminders) {
      Serial.println("Saving reminder at: " + String(dailyMillis));
      reminderTimes[reminders] = dailyMillis;
      reminders++;        
    }
    return true;
}

void MedReminderStateMachine::enterSavingReminder() {}
 
void MedReminderStateMachine::exitSavingReminder() {}
 