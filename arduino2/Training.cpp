#pragma once
#include <Arduino.h>
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

int millis2 = 0;
void MedReminderStateMachine::enterTraining() {
    // Actions to perform on entering Training
}

void MedReminderStateMachine::exitTraining() {
    // Actions to perform on exiting Training
}

bool MedReminderStateMachine::hasTraining_MovementDetected() {
    // Check condition for MovementDetected in Training state
    if (millis() < millisPerDay) {
      Serial.println("Movement detected");
      delay((int)(millisPerDay / 4));
      return true;
    }
    return false; // Placeholder implementation
}
bool MedReminderStateMachine::hasTraining_NewDay() {
    // Check condition for NewDay in Training state
    bool isFirstDay = millis() < millisPerDay;
    //Serial.println("Checking for first day: " + String(millis()) + " < " + String(millisPerDay) + "?");
    // return false;
    if (!isFirstDay) {
      return true;
    } 
}