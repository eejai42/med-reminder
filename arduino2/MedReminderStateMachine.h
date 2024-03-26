#pragma once
// Adjusted StateMachine.h Template for MedReminderStateMachine
#include "common.h"

enum class State {
    Training,
    SavingReminder,
    Idle,
    AboutToAlert,
    Alerting,
    ClearReminder,
    // Add additional states here
};

void checkingState();
void transitioning(State fromState, State toState);
void transitioned(State fromState, State toState);
String stateToString(State stateToStringify);

class MedReminderStateMachine {
private:
    State currentState;

public:
    MedReminderStateMachine();
    void checkState();

    // State transition utility methods
    void transitionTo(State newState);
    void onExit(State state);
    void onEnter(State state);

    // Enter and Exit methods for Training state
    void enterTraining();
    void exitTraining();

    // Action handlers for the Training state
    bool hasTraining_MovementDetected();
    bool hasTraining_NewDay();
    // Enter and Exit methods for SavingReminder state
    void enterSavingReminder();
    void exitSavingReminder();

    // Action handlers for the SavingReminder state
    bool hasSavingReminder_ReminderSaved();
    // Enter and Exit methods for Idle state
    void enterIdle();
    void exitIdle();

    // Action handlers for the Idle state
    bool hasIdle_WithinMSOfNextReminder();
    // Enter and Exit methods for AboutToAlert state
    void enterAboutToAlert();
    void exitAboutToAlert();

    // Action handlers for the AboutToAlert state
    bool hasAboutToAlert_ReminderTimeReached();
    bool hasAboutToAlert_MovementDetected();
    // Enter and Exit methods for Alerting state
    void enterAlerting();
    void exitAlerting();

    // Action handlers for the Alerting state
    bool hasAlerting_MainInputDoubleClicked();
    bool hasAlerting_SystemButtonPushed();
    bool hasAlerting_MovementDetected();
    // Enter and Exit methods for ClearReminder state
    void enterClearReminder();
    void exitClearReminder();

    // Action handlers for the ClearReminder state
    bool hasClearReminder_ReminderCleared();
};

extern MedReminderStateMachine* stateMachine;