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


class BaseBootup : public BaseState {
public:
    BaseBootup(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasBootupCompleted();
};

class BaseGatherReminders : public BaseState {
public:
    BaseGatherReminders(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasGatheringRemindersCompleted();
};

class BaseSaveReminders : public BaseState {
public:
    BaseSaveReminders(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasRemindersSaved();
};

class BaseReminding : public BaseState {
public:
    BaseReminding(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasWheelMoved();
};

class BaseIdle : public BaseState {
public:
    BaseIdle(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderTimeReached();
    virtual bool hasWheelMoved();
};

class BaseDebounceMovement : public BaseState {
public:
    BaseDebounceMovement(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderDebounceFailed();
    virtual bool hasDebounceFailed();
    virtual bool hasDebouncePassed();
};

class BaseCountMovement : public BaseState {
public:
    BaseCountMovement(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasMovementCounted();
};

class BaseWaitForMoreMovement : public BaseState {
public:
    BaseWaitForMoreMovement(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasWheelMoved();
    virtual bool hasWheelNotMoved();
};

class BaseMovementDetected : public BaseState {
public:
    BaseMovementDetected(BaseStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasMovementHandled();
};