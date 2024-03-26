#pragma once
#include <Arduino.h>
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

bool MedReminderStateMachine::hasTraining_MovementDetected() {
    // Check condition for MovementDetected in Training state
    Serial.println("Movement detected");
    delay((int)(millisPerDay / 4));
    return true;
}
bool MedReminderStateMachine::hasTraining_NewDay() {
    // Check condition for NewDay in Training state
    bool firstDayHasPassed = millis() > millisPerDay;
    return firstDayHasPassed;
}