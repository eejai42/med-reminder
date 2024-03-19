#pragma once
#include "BaseState.h"
#include "BaseStateMachine.h"
#include <memory>
#include <iostream>

// ***************************************************************
// Declaration for MedReminderStateMachine and base state classes
// ***************************************************************

class MedReminderStateMachine : public BaseStateMachine<BaseState<MedReminderStateMachine>> {
public:
    MedReminderStateMachine();

    // Other member functions...
};


class BaseBootup : public BaseState<MedReminderStateMachine> {
public:
    BaseBootup(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasBootupCompleted();
};

class BaseGatherReminders : public BaseState<MedReminderStateMachine> {
public:
    BaseGatherReminders(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasGatheringRemindersCompleted();
};

class BaseSaveReminders : public BaseState<MedReminderStateMachine> {
public:
    BaseSaveReminders(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasRemindersSaved();
};

class BaseReminding : public BaseState<MedReminderStateMachine> {
public:
    BaseReminding(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasWheelMoved();
};

class BaseIdle : public BaseState<MedReminderStateMachine> {
public:
    BaseIdle(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderTimeReached();
    virtual bool hasWheelMoved();
};

class BaseDebounceMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseDebounceMovement(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasReminderDebounceFailed();
    virtual bool hasDebounceFailed();
    virtual bool hasDebouncePassed();
};

class BaseCountMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseCountMovement(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasMovementCounted();
};

class BaseWaitForMoreMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseWaitForMoreMovement(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasWheelMoved();
    virtual bool hasWheelNotMoved();
};

class BaseMovementDetected : public BaseState<MedReminderStateMachine> {
public:
    BaseMovementDetected(MedReminderStateMachine* machine);

    void onEnter() override;
    void onExit() override;
    void onCheck() override;

    virtual bool hasMovementHandled();
};