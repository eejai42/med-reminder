#pragma once
#include <Arduino.h>

enum class State {
    Training,
    SavingReminder,
    Idle,
    AboutToAlert,
    Alerting,
    ClearReminder,
    // Add additional states here
};

class MedReminderStateMachineBase {
protected:
    State currentState;
    int beepsBeeped = 0;
    virtual void checkingState() {};
    virtual String stateToString(State stateToStringify);

public:
    MedReminderStateMachineBase();
    void checkState();

    // State transition utility methods
    virtual void transitionTo(State newState);
    virtual void onExit(State fromState, State toState);
    virtual void onEnter(State fromState, State toState);
        
    virtual void beep(int duration = 1000);
    virtual void emitAlarmBeep();


    // Enter and Exit methods for Training state
    virtual void enterTraining() {};
    virtual void exitTraining() {};

    // Action handlers for the Training state
    virtual bool hasTraining_MovementDetected() { return false; };
    virtual bool hasTraining_NewDay() { return false; };
    // Enter and Exit methods for SavingReminder state
    virtual void enterSavingReminder() {};
    virtual void exitSavingReminder() {};

    // Action handlers for the SavingReminder state
    virtual bool hasSavingReminder_ReminderSaved() { return false; };
    // Enter and Exit methods for Idle state
    virtual void enterIdle() {};
    virtual void exitIdle() {};

    // Action handlers for the Idle state
    virtual bool hasIdle_WithinMSOfNextReminder() { return false; };
    // Enter and Exit methods for AboutToAlert state
    virtual void enterAboutToAlert() {};
    virtual void exitAboutToAlert() {};

    // Action handlers for the AboutToAlert state
    virtual bool hasAboutToAlert_ReminderTimeReached() { return false; };
    virtual bool hasAboutToAlert_MovementDetected() { return false; };
    // Enter and Exit methods for Alerting state
    virtual void enterAlerting() {};
    virtual void exitAlerting() {};

    // Action handlers for the Alerting state
    virtual bool hasAlerting_MainInputDoubleClicked() { return false; };
    virtual bool hasAlerting_SystemButtonPushed() { return false; };
    virtual bool hasAlerting_MovementDetected() { return false; };
    // Enter and Exit methods for ClearReminder state
    virtual void enterClearReminder() {};
    virtual void exitClearReminder() {};

    // Action handlers for the ClearReminder state
    virtual bool hasClearReminder_ReminderCleared() { return false; };
};
