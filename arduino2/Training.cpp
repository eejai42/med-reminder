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
    return millis() > millisPerDay;
}

void MedReminderStateMachine::enterTraining() {
    Serial.println("\nStartinging first day - training for the next 24 hours.");
    delay(1000);
}

void MedReminderStateMachine::exitTraining() {}