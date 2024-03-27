#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasAlerting_MovementDetected() {
    Serial.println("Movement detected - returning to idle.");
    return true;
}

void MedReminderStateMachine::enterAlerting() {
  Serial.println("Alerting");
  delay(25 * millisPerSecond);
}

