// main.cpp
#include "Arduino.h"
#include "constants.h"
#include "beep_helpers.h"
#include "wheel_helpers.h"

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  setupBeeps(); // Initialize speaker pin
  setupWheel(); // Initialize wheel sensor pins
}


void loop() {
  //Main loop code to check wheel movement, play beeps, and handle time reminders

  checkState();

  // Example: Detect and handle debounced wheel movement
  if (movementDetected()) {
    printAndClearMovement();
  } 
}
