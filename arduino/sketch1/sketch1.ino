// main.cpp
#include "Arduino.h"
#include "constants.h"
#include "alarm_helpers.h"
#include "wheel_helpers.h"

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(2500);
  Serial.print("Configuring med-alarm now");  
  setupAlarms(); // Initialize speaker pin
  setupWheel(); // Initialize wheel sensor pins
  for (int i = 0; i < 3; i++) {
    delay(750);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Done.");  
}


void loop() {
  //Main loop code to check wheel movement, play beeps, and handle time reminders

  checkState();

  // Example: Detect and handle debounced wheel movement
  if (movementDetected()) {
    printAndClearMovement();
    triggerTimer();
  } 

  checkAlarms();
}
