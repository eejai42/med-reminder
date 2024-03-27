#pragma once
#include "MedReminderStateMachine.h"

#include "Constants.h"

bool training = true;

bool MedReminderStateMachine::hasIdle_WithinMSOfNextReminder() {
    for(int i = 0; i < reminders; i++) {
        if ((dailyMillis < reminderTimes[i]) &&
            (dailyMillis > (reminderTimes[i] - (millisPerSecond * 2)))) {
            Serial.println("reminder time: " + String(reminderTimes[i]) + " - mps: " + String(millisPerSecond) + " - Current state: " + String(stateToString(currentState)));
            return true;
        } 
    }
    return false;
}

void MedReminderStateMachine::enterIdle() {
    if (training) {
      Serial.println("Done training.");
      training = false;
    }    
}
