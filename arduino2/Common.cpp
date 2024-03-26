#pragma once

#include "Constants.h"
#include "MedReminderStateMachine.h"
#include "Common.h"

int dailyMillis = 0;
int millisPerDay = ms_per_minute * minutes_per_day;

int reminders = 0;
int beepsBeeped = 0;

void checkingState() {
  dailyMillis = millis() % millisPerDay;
}

void transitioning(State fromState, State toState) {
  Serial.println(" - transitioning " + String((int)fromState));
}
void transitioned(State fromState, State toState) {

}


void beep(int duration = 1000) {
  tone(status_beeps_speaker, 440, ms_between_beeps * 2);
  digitalWrite(status_status_led, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(ms_between_beeps);       // Wait for a second (1000 milliseconds)
  digitalWrite(status_status_led, LOW);   // Turn the LED off by making the voltage LOW
  delay(ms_between_beeps);       // Wait for a second (1000 milliseconds)
}

void emitAlarmBeep() {
  //Serial.println("beeping");
  beep(ms_between_beeps);
  beepsBeeped++;
}

