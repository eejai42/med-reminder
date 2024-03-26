#pragma once
#include <Arduino.h>
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

unsigned long lastMovementDetected = 0;
bool MedReminderStateMachine::hasTraining_MovementDetected() {
    // Check condition for MovementDetected in Training state
    unsigned long reminderDurationGoal = (int)(millisPerDay / 2);

    if (millis() > lastMovementDetected + (millisPerSecond * 3)) {
      if ((dailyMillis % reminderDurationGoal) > reminderDurationGoal - millisPerSecond) {
        lastMovementDetected = millis();
      Serial.println("MOVEMENT: " + String(millis()));
        return true;
      } 
    }
    return false;
}
bool MedReminderStateMachine::hasTraining_NewDay() {
    // Check condition for NewDay in Training state
    bool firstDayHasPassed = millis() > millisPerDay;    
    if (firstDayHasPassed) {
      Serial.println("First day has passed" + String(millis()));
    }
    return firstDayHasPassed;
}

void MedReminderStateMachine::enterTraining() {
    // Actions to perform on entering Training
}

void MedReminderStateMachine::exitTraining() {
    // Actions to perform on exiting Training
}