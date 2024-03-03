#include "Arduino.h"
#include "constants.h"
#include "wheel_helpers.h"
#include "alarm_helpers.h"

// Timer states
unsigned long timer1 = 0;  // Minute mark for the first timer
unsigned long timer2 = 0;  // Minute mark for the second timer
unsigned long minutesPerDay = 6;
unsigned long currentMinutes = 0;
bool timer1Set = false;
bool timer2Set = false;

void setupAlarms() {
  pinMode(speakerPin, OUTPUT);
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
  if (millis() < 10000) {
    Serial.println(" ----- IGNORING INITIAL MOVEMENT DETECTION ----");
  } else if (!timer1Set) {
    timer1 = currentMinutes;
    timer1Set = true;
    Serial.print("Timer1 set for minute: ");
    Serial.println(timer1);
  } else if (!timer2Set) {
    timer2 = currentMinutes;
    timer2Set = true;
    Serial.print("Timer2 set for minute: ");
    Serial.println(timer2);
  }
}

unsigned long minutes_since_day_started() {
  return (millis() / 60000) % minutesPerDay;  // Convert milliseconds to minutes
}

void checkTimers() {
  if (timer1Set || timer2Set) {
    unsigned long currentMinutes = minutes_since_day_started();

    if (timer1Set && currentMinutes == timer1) {
      Serial.println("Timer1 reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
      timer1Set = false;  // or adjust as needed
    }
    if (timer2Set && currentMinutes == timer2) {
      Serial.println("Timer2 reached: time2 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
      timer2Set = false;  // or adjust as needed
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
