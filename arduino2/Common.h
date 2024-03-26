#pragma once

#include <Arduino.h>

#include "MedReminderStateMachine.h"

extern unsigned long millisPerDay;
extern unsigned long dailyMillis; 
extern int reminders;

void beep(int duration = 1000);
void emitAlarmBeep();
