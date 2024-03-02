// beep_helpers.cpp
#include "Arduino.h"
#include "constants.h"
#include "beep_helpers.h"

void setupBeeps() {
  pinMode(speakerPin, OUTPUT);
}

void beep(int duration = 1000) {
  digitalWrite(speakerPin, HIGH); // Turn the LED on (HIGH is the voltage level)
  delay(duration);          // Wait for a second (1000 milliseconds)
  digitalWrite(speakerPin, LOW);  // Turn the LED off by making the voltage LOW
}

void emitBeepSequence(int duration, int beepCount) {
  for (int i = 0; i < beepCount; ++i) {
    beep(duration);
    delay(duration); // Delay between beeps
  }
}
