#pragma once
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

bool training = true;

bool MedReminderStateMachine::hasIdle_WithinMSOfNextReminder() {
    for(int i = 0; i < reminders; i++) {
        if ((dailyMillis < reminderTimes[i]) &&
            (dailyMillis > (reminderTimes[i] - (millisPerSecond * 2)))) {
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
    
    Serial.println("Idle - waiting for reminders.");
}

void MedReminderStateMachine::exitIdle() {}