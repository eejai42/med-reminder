// main.cpp
#include <Arduino.h>
#include "Constants.h"
#include "MedReminderStateMachine.h"



void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  stateMachine = new MedReminderStateMachine();
  // setupAlarms(); // Initialize speaker p
  // setupWheel(); // Initialize wheel sensor pins
  // simulateSetupTime(); // setup time.
}


void loop() {
  //Main loop code to check wheel movement, play beeps, and handle time reminders
  stateMachine->checkState();
  // checkState();

  // // Example: Detect and handle debounced wheel movement
  // if (movementDetected()) {
  //   printAndClearMovement();
  //   triggerTimer();
  // } 

  //checkAlarms();
}
