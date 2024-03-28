#pragma once

#include "Constants.h"
#include "MedReminderStateMachineBase.h"
#include "MedReminderStateMachine.h"

void MedReminderStateMachine::checkingState() {  
  if (millis() < 100 && dailyMillis == 0) {
    delay(1000);
    Serial.println("\nStartinging first day - training for the next 24 hours.");
  }
  dailyMillis = millis() % millisPerDay;
}

void MedReminderStateMachine::onEnter(State fromState, State toState) {
  MedReminderStateMachineBase::onEnter(fromState, toState);
  Serial.println("Transition from: " + stateToString(fromState) + " -> " + stateToString(toState));
}