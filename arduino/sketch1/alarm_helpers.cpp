#include "Arduino.h"
#include "constants.h"
#include "wheel_helpers.h"
#include "alarm_helpers.h"

// Timer states
unsigned long timer = 0;  // Minute mark for the second timer
unsigned long currentMinutes = 0;
int initialDay = 0;
int currentDay = (initialDay + ((millis() / msPerMinute) / minutesPerDay) % 14) + 1;
bool timerSet = false;

int getTimer2Minutes() {
  return timer;
}

int days_into_cycle() {
  return currentDay;
}

void setupAlarms() {
  pinMode(speakerPin, OUTPUT);
  DayTime dt = getDayAndTime();
  initialDay = dt.dow;
}

void checkAlarms() {
  unsigned long tempMinutes = minutes_since_day_started();
  if (tempMinutes != currentMinutes) {
    currentMinutes = tempMinutes;
    if ((millis() % 1000) < 10) {
      Serial.print(" ----- TOP OF THE MINUTE:  ----");
      Serial.print(currentMinutes);
      Serial.print(" -> ");
      Serial.println(millis() % 1000);
      printDowTod();
    }
  }
}

void triggerTimer() {
  unsigned long currentMinutes = minutes_since_day_started();
  if (millis() < 9000) {
    Serial.println("Timer 1 set for minute: 0");
    printDowTod();
  } else if (!timerSet && (currentMinutes > 0)) {
    Serial.print("Timer 2 set for minutes: ");
    Serial.println(currentMinutes);
    printDowTod();
    timer = currentMinutes;
    timerSet = true;
  }
}

unsigned long minutes_since_day_started() {
  return (millis() / msPerMinute) % minutesPerDay;  // Convert milliseconds to minutes
}

void checkTimers() {
  if (timerSet) {
    unsigned long currentMinutes = minutes_since_day_started();

    if (currentMinutes == 0) {
      Serial.println("Timer reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }

    if (currentMinutes == timer) {
      Serial.println("Timer2 reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }
  }
}

void beep(int duration = 1000) {
  digitalWrite(speakerPin, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(duration);                 // Wait for a second (1000 milliseconds)
  digitalWrite(speakerPin, LOW);   // Turn the LED off by making the voltage LOW
}

void emitBeepSequence(int duration, int beepCount) {
  for (int i = 0; i < beepCount; ++i) {
    beep(duration);
    delay(duration);  // Delay between beeps
  }
}
