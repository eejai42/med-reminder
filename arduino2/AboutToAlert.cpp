#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasAboutToAlert_ReminderTimeReached() {
    for(int i = 0; i < reminders; i++) {
        if ((dailyMillis > reminderTimes[i]) &&
            (dailyMillis < (reminderTimes[i] + (millisPerSecond * 5)))) {
            Serial.println("Reminder is within 5 seconds");                
            return true;
        }
    }
    return false;
}
bool MedReminderStateMachine::hasAboutToAlert_MovementDetected() {
    return false;
}

void MedReminderStateMachine::enterAboutToAlert() {}

void MedReminderStateMachine::exitAboutToAlert() {}