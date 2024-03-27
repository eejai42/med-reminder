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
  } 
  return isNewDay;
}

void MedReminderStateMachine::enterTraining() {}

void MedReminderStateMachine::exitTraining() {}