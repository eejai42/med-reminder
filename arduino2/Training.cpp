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
    Serial.println("Checking for movement");
    delay(2000);
    if (millis() > 5000) return true;
    return false; // Placeholder implementation
}
bool MedReminderStateMachine::hasTraining_NewDay() {
    // Check condition for NewDay in Training state
    bool isFirstDay = millis() > dailyMillis;
    if (ms_per_minute == 24) {
      millis2 = 5;
    }
    if (!isFirstDay) {
      return true;
    } 
}