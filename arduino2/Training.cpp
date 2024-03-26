#pragma once
#include <Arduino.h>
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

unsigned long lastMovementDetected = 0;
bool MedReminderStateMachine::hasTraining_MovementDetected() {
    unsigned long reminderDurationGoal = (int)(millisPerDay / 2);

    if (millis() > lastMovementDetected + (millisPerSecond * 3)) {
      if ((dailyMillis % reminderDurationGoal) > reminderDurationGoal - millisPerSecond) {
        lastMovementDetected = millis();
        return true;
      } 
    }
    return false;
}
bool MedReminderStateMachine::hasTraining_NewDay() {
  bool isNewDay = millis() > millisPerDay;
  if (isNewDay) {
    Serial.println("New day reqached");
  } else {
    Serial.println("Not new day: " + String(millis()) + " - " + millisPerDay);
  }
  return isNewDay;
}

void MedReminderStateMachine::enterTraining() {
    Serial.println("\nStartinging first day - training for the next 24 hours.");
    delay(1000);
}

void MedReminderStateMachine::exitTraining() {}