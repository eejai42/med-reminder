#pragma once
// Adjusted StateMachine.h Template for MedReminderStateMachine

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
  virtual void checkingState(){};
  virtual String stateToString(State stateToStringify);

public:
  MedReminderStateMachineBase();
  virtual void checkState();

  // State transition utility methods
  virtual void transitionTo(State newState);
  virtual void onExit(State fromState, State toState);
  virtual void onEnter(State fromState, State toState);

  virtual void beep(int duration = 1000);
  virtual void emitAlarmBeep();

  // Enter and Exit methods for Training state
  virtual void enterTraining(State lastState){};
  virtual void exitTraining(State nextState){};

  // Action handlers for the Training state
  virtual bool hasTraining_MovementDetected() {
    return false;
  };
  virtual bool hasTraining_NewDay() {
    return false;
  };
  // Enter and Exit methods for SavingReminder state
  virtual void enterSavingReminder(State lastState){};
  virtual void exitSavingReminder(State nextState){};

  // Action handlers for the SavingReminder state
  virtual bool hasSavingReminder_ReminderSaved() {
    return false;
  };
  // Enter and Exit methods for Idle state
  virtual void enterIdle(State lastState){};
  virtual void exitIdle(State nextState){};

  // Action handlers for the Idle state
  virtual bool hasIdle_WithinMSOfNextReminder() {
    return false;
  };
  // Enter and Exit methods for AboutToAlert state
  virtual void enterAboutToAlert(State lastState){};
  virtual void exitAboutToAlert(State nextState){};

  // Action handlers for the AboutToAlert state
  virtual bool hasAboutToAlert_ReminderTimeReached() {
    return false;
  };
  virtual bool hasAboutToAlert_MovementDetected() {
    return false;
  };
  // Enter and Exit methods for Alerting state
  virtual void enterAlerting(State lastState){};
  virtual void exitAlerting(State nextState){};

  // Action handlers for the Alerting state
  virtual bool hasAlerting_MainInputDoubleClicked() {
    return false;
  };
  virtual bool hasAlerting_SystemButtonPushed() {
    return false;
  };
  virtual bool hasAlerting_MovementDetected() {
    return false;
  };
  // Enter and Exit methods for ClearReminder state
  virtual void enterClearReminder(State lastState){};
  virtual void exitClearReminder(State nextState){};

  // Action handlers for the ClearReminder state
  virtual bool hasClearReminder_ReminderCleared() {
    return false;
  };
};