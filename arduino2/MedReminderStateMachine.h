#pragma once

#include <Arduino.h>
#include "Constants.h"
#include "MedReminderStateMachineBase.h"


class MedReminderStateMachine : public MedReminderStateMachineBase {
protected:
  static const unsigned int maxReminders = 24;
  unsigned int reminders = 0;
  unsigned long dailyMillis = 0;
  unsigned long millisPerSecond = (int)(ms_per_minute / 60);
  unsigned long millisPerDay = (long)ms_per_minute * (long)minutes_per_day;
  unsigned long reminderTimes[maxReminders];
public:
  void checkingState() override;

  void onEnter(State fromState, State toState) override;

  bool hasIdle_WithinMSOfNextReminder() override;

  void enterIdle(State currentState) override;

  bool hasAboutToAlert_ReminderTimeReached() override;
      
  bool hasAboutToAlert_MovementDetected() override;
   
  bool hasSavingReminder_ReminderSaved() override;
  bool hasClearReminder_ReminderCleared() override;
  bool hasAlerting_MovementDetected() override;
  void enterAlerting(State currentState) override;

  void enterAboutToAlert(State currentState) override;

  bool hasTraining_MovementDetected() override;
  bool hasTraining_NewDay() override;
};
