// main.cpp
#include "Arduino.h"
#include "beep_helpers.cpp"
#include "wheel_helpers.cpp"

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  setupWheel(); // Initialize wheel sensor pins
}

void loop() {
  // Main loop code to check wheel movement, play beeps, and handle time reminders
  checkState();

  // Example: Detect and handle debounced wheel movement
  if (movementDetected()) {
    int spotsMoved = getMovementCount();
    // Handle wheel movement (e.g., update state, play confirmation beep)
    emitBeepSequence(0, spotsMoved); // Example usage of emitBeepSequence
    clearMovement(); //
  }

  // Other functionalities as per project requirements
}