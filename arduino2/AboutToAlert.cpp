#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasAboutToAlert_ReminderTimeReached() {
  if (dailyMillis < 100) return true;
  for(int i = 0; i < reminders; i++) {
      if ((dailyMillis > reminderTimes[i]) &&
          (dailyMillis < (reminderTimes[i] + (millisPerSecond * 5)))) {
          Serial.println("Reminder is within 5 seconds");                            
          return true;
      }
  }
  return false;
}

void MedReminderStateMachine::enterAboutToAlert() {
  Serial.println("Altering in 3 seconds");
  delay(millisPerSecond * 3);
}
