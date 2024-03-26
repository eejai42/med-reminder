#pragma once

#include "Constants.h"
#include "MedReminderStateMachine.h"
#include "Common.h"

unsigned long dailyMillis = 0;
unsigned long millisPerDay = (long)(ms_per_minute * (long)minutes_per_day);
unsigned int millisPerSecond = (long)(ms_per_minute / 60);

unsigned long reminderTimes[maxReminders]; // Define the storage for reminder times
unsigned int reminders = 0;
int beepsBeeped = 0;

void checkingState() {
  dailyMillis = millis() % millisPerDay;
}

void transitioning(State fromState, State toState) {}
void transitioned(State fromState, State toState) {}

void beep(int duration = 1000) {
  tone(status_beeps_speaker, 440, ms_between_beeps * 2);
  digitalWrite(status_status_led, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(ms_between_beeps);       // Wait for a second (1000 milliseconds)
  digitalWrite(status_status_led, LOW);   // Turn the LED off by making the voltage LOW
  delay(ms_between_beeps);       // Wait for a second (1000 milliseconds)
}

void emitAlarmBeep() {
  beep(ms_between_beeps);
  beepsBeeped++;
}

