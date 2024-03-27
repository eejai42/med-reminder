#pragma once
// Adjusted StateMachine.cpp Template for MedReminderStateMachine
#include "MedReminderStateMachineBase.h"
#include "MedReminderStateMachine.h"

MedReminderStateMachineBase::MedReminderStateMachineBase() 
: currentState(State::Training) {
  onEnter(State::Idle, currentState);  // Initial state entry actions
}

void MedReminderStateMachineBase::checkState() {
  checkingState();
  switch (currentState) {
    case State::Training:
      if (hasTraining_MovementDetected()) {
        transitionTo(State::SavingReminder);  // Transition based on specific action being true
        return;
      }
      if (hasTraining_NewDay()) {
        transitionTo(State::Idle);  // Transition based on specific action being true
        return;
      }
      break;
    case State::SavingReminder:
      if (hasSavingReminder_ReminderSaved()) {
        transitionTo(State::Training);  // Transition based on specific action being true
        return;
      }
      break;
    case State::Idle:
      if (hasIdle_WithinMSOfNextReminder()) {
        transitionTo(State::AboutToAlert);  // Transition based on specific action being true
        return;
      }
      break;
    case State::AboutToAlert:
      if (hasAboutToAlert_ReminderTimeReached()) {
        transitionTo(State::Alerting);  // Transition based on specific action being true
        return;
      }
      if (hasAboutToAlert_MovementDetected()) {
        transitionTo(State::ClearReminder);  // Transition based on specific action being true
        return;
      }
      break;
    case State::Alerting:
      if (hasAlerting_MainInputDoubleClicked()) {
        transitionTo(State::Training);  // Transition based on specific action being true
        return;
      }
      if (hasAlerting_SystemButtonPushed()) {
        transitionTo(State::ClearReminder);  // Transition based on specific action being true
        return;
      }
      if (hasAlerting_MovementDetected()) {
        transitionTo(State::ClearReminder);  // Transition based on specific action being true
        return;
      }
      break;
    case State::ClearReminder:
      if (hasClearReminder_ReminderCleared()) {
        transitionTo(State::Idle);  // Transition based on specific action being true
        return;
      }
      break;
  }
}

void MedReminderStateMachineBase::transitionTo(State newState) {
  onExit(currentState, newState);
  State lastState = currentState;
  currentState = newState;
  onEnter(lastState, currentState);
}

void MedReminderStateMachineBase::onExit(State currentState, State newState) {
  switch (currentState) {
    case State::Training:
      exitTraining();
      break;
    case State::SavingReminder:
      exitSavingReminder();
      break;
    case State::Idle:
      exitIdle();
      break;
    case State::AboutToAlert:
      exitAboutToAlert();
      break;
    case State::Alerting:
      exitAlerting();
      break;
    case State::ClearReminder:
      exitClearReminder();
      break;
  }
}

void MedReminderStateMachineBase::onEnter(State currentState, State newState) {
  switch (currentState) {
    case State::Training:
      enterTraining();
      break;
    case State::SavingReminder:
      enterSavingReminder();
      break;
    case State::Idle:
      enterIdle();
      break;
    case State::AboutToAlert:
      enterAboutToAlert();
      break;
    case State::Alerting:
      enterAlerting();
      break;
    case State::ClearReminder:
      enterClearReminder();
      break;
  }
}

void MedReminderStateMachineBase::beep(int duration = 1000) {
  tone(status_beeps_speaker, 440, ms_between_beeps * 2);
  digitalWrite(status_status_led, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(ms_between_beeps);                // Wait for a second (1000 milliseconds)
  digitalWrite(status_status_led, LOW);   // Turn the LED off by making the voltage LOW
  delay(ms_between_beeps);                // Wait for a second (1000 milliseconds)
}

void MedReminderStateMachineBase::emitAlarmBeep() {
  beep(ms_between_beeps);
  beepsBeeped++;
}

String MedReminderStateMachineBase::stateToString(State stateToStringify) {
  switch (stateToStringify) {
    case State::Training:
      return "Training";
      break;
    case State::SavingReminder:
      return "SavingReminder";
      break;
    case State::Idle:
      return "Idle";
      break;
    case State::AboutToAlert:
      return "AboutToAlert";
      break;
    case State::Alerting:
      return "Alerting";
      break;
    case State::ClearReminder:
      return "ClearReminder";
      break;
    default:
      return "Unknown State enum value: " + String((int)stateToStringify);
  }
}

MedReminderStateMachine* stateMachine = nullptr;