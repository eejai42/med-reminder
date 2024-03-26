// main.cpp
#pragma once
#include <Arduino.h>
#include "MedReminderStateMachine.h"

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  stateMachine = new MedReminderStateMachine();
}

void loop() {
  stateMachine->checkState();
}

