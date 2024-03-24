#pragma once
#include "BaseState.h"
#include "BaseStateMachine.h"
#include <memory>
#include <iostream>

// ***************************************************************
// Declaration for MedReminderStateMachine and base state classes
// ***************************************************************

class MedReminderStateMachine : public BaseStateMachine {
public:
    MedReminderStateMachine();

    // Other member functions...
};


class BaseTraining : public BaseState {
public:
    BaseTraining(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasMovementDetected();
    virtual bool hasNewDay();
};

class BaseSavingReminder : public BaseState {
public:
    BaseSavingReminder(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderSaved();
};

class BaseIdle : public BaseState {
public:
    BaseIdle(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasWithinMSOfNextReminder();
};

class BaseAboutToAlert : public BaseState {
public:
    BaseAboutToAlert(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderTimeReached();
    virtual bool hasMovementDetected();
};

class BaseAlerting : public BaseState {
public:
    BaseAlerting(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasSystemButtonPushed();
    virtual bool hasMovementDetected();
};

class BaseClearReminder : public BaseState {
public:
    BaseClearReminder(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderCleared();
};