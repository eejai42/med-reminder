#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasAlerting_MovementDetected() { return true; }

void MedReminderStateMachine::enterAlerting() {
  Serial.println("Alerting");
  delay(25 * millisPerSecond);
}

