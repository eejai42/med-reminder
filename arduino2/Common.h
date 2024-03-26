#pragma once

#include <Arduino.h>

#include "MedReminderStateMachine.h"

extern unsigned long millisPerDay;
extern unsigned long dailyMillis; 
extern unsigned int millisPerSecond;

static const int maxReminders = 24; // Maximum number of reminders
extern unsigned int reminders; // Counter for the number of reminders
extern unsigned long reminderTimes[maxReminders]; // Array to store reminder times


void beep(int duration = 1000);
void emitAlarmBeep();
