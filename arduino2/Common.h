#pragma once

#include <Arduino.h>

#include "MedReminderStateMachine.h"

extern int millisPerDay;
extern int dailyMillis; 

void beep(int duration = 1000);
void emitAlarmBeep();
