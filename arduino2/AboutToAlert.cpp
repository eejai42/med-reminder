#pragma once
#include "MedReminderStateMachine.h"

bool MedReminderStateMachine::hasAboutToAlert_ReminderTimeReached() {
    // Check condition for ReminderTimeReached in AboutToAlert state
    for(int i = 0; i < reminders; i++) {
        if ((dailyMillis > reminderTimes[i]) &&
            (dailyMillis < (reminderTimes[i] + (millisPerSecond * 5)))) {
            Serial.println("Reminder is within 5 seconds");                
            return true;
        }
    }
    return false; // Placeholder implementation
}
bool MedReminderStateMachine::hasAboutToAlert_MovementDetected() {
    // Check condition for MovementDetected in AboutToAlert state
    return false; // Placeholder implementation
}

void MedReminderStateMachine::enterAboutToAlert() {
    // Actions to perform on entering AboutToAlert
}

void MedReminderStateMachine::exitAboutToAlert() {
    // Actions to perform on exiting AboutToAlert
}