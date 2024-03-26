#pragma once

#include <Arduino.h>
// Adjusted StateMachine.cpp Template for MedReminderStateMachine
#include "MedReminderStateMachine.h"

MedReminderStateMachine::MedReminderStateMachine() : currentState(State::Training) {
    onEnter(currentState); // Initial state entry actions
}

void MedReminderStateMachine::checkState() {
    checkingState();
    switch (currentState) {
        case State::Training:
            if (hasTraining_MovementDetected()) {
                transitionTo(State::SavingReminder); // Transition based on specific action being true
                return;
            }
            if (hasTraining_NewDay()) {
                transitionTo(State::Idle); // Transition based on specific action being true
                return;
            }
            break;
        case State::SavingReminder:
            if (hasSavingReminder_ReminderSaved()) {
                transitionTo(State::Training); // Transition based on specific action being true
                return;
            }
            break;
        case State::Idle:
            if (hasIdle_WithinMSOfNextReminder()) {
                transitionTo(State::AboutToAlert); // Transition based on specific action being true
                return;
            }
            break;
        case State::AboutToAlert:
            if (hasAboutToAlert_ReminderTimeReached()) {
                transitionTo(State::Alerting); // Transition based on specific action being true
                return;
            }
            if (hasAboutToAlert_MovementDetected()) {
                transitionTo(State::ClearReminder); // Transition based on specific action being true
                return;
            }
            break;
        case State::Alerting:
            if (hasAlerting_MainInputDoubleClicked()) {
                transitionTo(State::Training); // Transition based on specific action being true
                return;
            }
            if (hasAlerting_SystemButtonPushed()) {
                transitionTo(State::ClearReminder); // Transition based on specific action being true
                return;
            }
            if (hasAlerting_MovementDetected()) {
                transitionTo(State::ClearReminder); // Transition based on specific action being true
                return;
            }
            break;
        case State::ClearReminder:
            if (hasClearReminder_ReminderCleared()) {
                transitionTo(State::Idle); // Transition based on specific action being true
                return;
            }
            break;
    }
}

void MedReminderStateMachine::transitionTo(State newState) {
    transitioning(currentState, newState);
    Serial.print("Transitioning from " + String((int)currentState) + " to " + String((int)newState));
    onExit(currentState);
    currentState = newState;
    onEnter(newState);
    transitioned(currentState, newState);
}

void MedReminderStateMachine::onExit(State state) {
    switch (state) {
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

void MedReminderStateMachine::onEnter(State state) {
    switch (state) {
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

MedReminderStateMachine* stateMachine = nullptr;