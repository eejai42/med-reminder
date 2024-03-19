#pragma once
// Adjusted StateMachine.cpp Template for MedReminderStateMachine
#include "MedReminderStateMachine.h"

MedReminderStateMachine::MedReminderStateMachine() : currentState(State::Bootup) {
    onEnter(currentState); // Initial state entry actions
}

void MedReminderStateMachine::checkState() {
    switch (currentState) {
        case State::Bootup:
            if (hasBootup_BootupCompleted()) {
                transitionTo(State::GatherReminders); // Transition based on specific action being true
                return;
            }
            break;
        case State::GatherReminders:
            if (hasGatherReminders_GatheringRemindersCompleted()) {
                transitionTo(State::SaveReminders); // Transition based on specific action being true
                return;
            }
            break;
        case State::SaveReminders:
            if (hasSaveReminders_RemindersSaved()) {
                transitionTo(State::Idle); // Transition based on specific action being true
                return;
            }
            break;
        case State::Reminding:
            if (hasReminding_WheelMoved()) {
                transitionTo(State::DebounceMovement); // Transition based on specific action being true
                return;
            }
            break;
        case State::Idle:
            if (hasIdle_ReminderTimeReached()) {
                transitionTo(State::Reminding); // Transition based on specific action being true
                return;
            }
            if (hasIdle_WheelMoved()) {
                transitionTo(State::DebounceMovement); // Transition based on specific action being true
                return;
            }
            break;
        case State::DebounceMovement:
            if (hasDebounceMovement_ReminderDebounceFailed()) {
                transitionTo(State::Reminding); // Transition based on specific action being true
                return;
            }
            if (hasDebounceMovement_DebounceFailed()) {
                transitionTo(State::Idle); // Transition based on specific action being true
                return;
            }
            if (hasDebounceMovement_DebouncePassed()) {
                transitionTo(State::CountMovement); // Transition based on specific action being true
                return;
            }
            break;
        case State::CountMovement:
            if (hasCountMovement_MovementCounted()) {
                transitionTo(State::WaitForMoreMovement); // Transition based on specific action being true
                return;
            }
            break;
        case State::WaitForMoreMovement:
            if (hasWaitForMoreMovement_WheelMoved()) {
                transitionTo(State::CountMovement); // Transition based on specific action being true
                return;
            }
            if (hasWaitForMoreMovement_WheelNotMoved()) {
                transitionTo(State::MovementDetected); // Transition based on specific action being true
                return;
            }
            break;
        case State::MovementDetected:
            if (hasMovementDetected_MovementHandled()) {
                transitionTo(State::Idle); // Transition based on specific action being true
                return;
            }
            break;
    }
}

void MedReminderStateMachine::transitionTo(State newState) {
    onExit(currentState);
    currentState = newState;
    onEnter(newState);
}

void MedReminderStateMachine::onExit(State state) {
    switch (state) {
        case State::Bootup:
            exitBootup();
            break;
        case State::GatherReminders:
            exitGatherReminders();
            break;
        case State::SaveReminders:
            exitSaveReminders();
            break;
        case State::Reminding:
            exitReminding();
            break;
        case State::Idle:
            exitIdle();
            break;
        case State::DebounceMovement:
            exitDebounceMovement();
            break;
        case State::CountMovement:
            exitCountMovement();
            break;
        case State::WaitForMoreMovement:
            exitWaitForMoreMovement();
            break;
        case State::MovementDetected:
            exitMovementDetected();
            break;
    }
}

void MedReminderStateMachine::onEnter(State state) {
    switch (state) {
        case State::Bootup:
            enterBootup();
            break;
        case State::GatherReminders:
            enterGatherReminders();
            break;
        case State::SaveReminders:
            enterSaveReminders();
            break;
        case State::Reminding:
            enterReminding();
            break;
        case State::Idle:
            enterIdle();
            break;
        case State::DebounceMovement:
            enterDebounceMovement();
            break;
        case State::CountMovement:
            enterCountMovement();
            break;
        case State::WaitForMoreMovement:
            enterWaitForMoreMovement();
            break;
        case State::MovementDetected:
            enterMovementDetected();
            break;
    }
}

MedReminderStateMachine* stateMachine = nullptr;