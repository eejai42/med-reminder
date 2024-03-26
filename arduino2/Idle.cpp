#pragma once
#include "MedReminderStateMachine.h"
#include "Constants.h"
#include "Common.h"

bool MedReminderStateMachine::hasIdle_WithinMSOfNextReminder() {
    // Check condition for WithinMSOfNextReminder in Idle state
    //int msPerSecond = ((int)ms_per_minute / 60);
    for(int i = 0; i < reminders; i++) {
        if ((dailyMillis < reminderTimes[i]) &&
            (dailyMillis > (reminderTimes[i] - (millisPerSecond * 2)))) { //} (msPerSecond * 5))))  {
           // Serial.println("Reminder is within 5 seconds.  Daily millis: " + String(dailyMillis) + " - based on this reminder time: " + String(reminderTimes[i]));                
            return true;
        } else {
            // Serial.println("Reminder is NOT within 5 seconds.  Daily millis: " + String(dailyMillis) + " - based on this reminder time: " + String(reminderTimes[i]));                
        }
    }
    return false; // Placeholder implementation
}

void MedReminderStateMachine::enterIdle() {
    // Actions to perform on entering Idle
}

void MedReminderStateMachine::exitIdle() {
    // Actions to perform on exiting Idle
}