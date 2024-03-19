#pragma once
#include "BaseState.h"
#include "BaseStateMachine.h"
#include <memory>
#include <iostream>
#include "Bootup.h"
#include "GatherReminders.h"
#include "SaveReminders.h"
#include "Reminding.h"
#include "Idle.h"
#include "DebounceMovement.h"
#include "CountMovement.h"
#include "WaitForMoreMovement.h"
#include "MovementDetected.h"

// ***************************************************************
// Generated State Machine Classes for MedReminder project
// ***************************************************************

class MedReminderStateMachine : public BaseStateMachine<BaseState<MedReminderStateMachine>> {
public:
    MedReminderStateMachine() : BaseStateMachine() {
        // Initialize the machine with the Bootup state
        changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new Bootup(this)));
    }    
};

class BaseBootup : public BaseState<MedReminderStateMachine> {
public:
    using BaseState::BaseState; 

    BaseBootup(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Initializes the system and prepares for operation.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for Bootup
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasBootupCompleted()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new GatherReminders(machine)));
            return;
        }
    }

    virtual bool hasBootupCompleted() {
        // Transition logic for BootupCompleted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseGatherReminders : public BaseState<MedReminderStateMachine> {
public:
    BaseGatherReminders(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Awaits the time for the first medication reminder.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for GatherReminders
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasGatheringRemindersCompleted()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new SaveReminders(machine)));
            return;
        }
    }

    virtual bool hasGatheringRemindersCompleted() {
        // Transition logic for GatheringRemindersCompleted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseSaveReminders : public BaseState<MedReminderStateMachine> {
public:
    BaseSaveReminders(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Captures the current time as a reference point for tracking.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for SaveReminders
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasRemindersSaved()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new Idle(machine)));
            return;
        }
    }

    virtual bool hasRemindersSaved() {
        // Transition logic for RemindersSaved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseReminding : public BaseState<MedReminderStateMachine> {
public:
    BaseReminding(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "" << std::endl;
    }

    void onExit() override {
        // Custom exit logic for Reminding
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasWheelMoved()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new DebounceMovement(machine)));
            return;
        }
    }

    virtual bool hasWheelMoved() {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseIdle : public BaseState<MedReminderStateMachine> {
public:
    using BaseState::BaseState; 
    BaseIdle(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "The system is in a standby mode, waiting for interaction or the next event.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for Idle
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasReminderTimeReached()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new Reminding(machine)));
            return;
        }
        if (this->hasWheelMoved()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new DebounceMovement(machine)));
            return;
        }
    }

    virtual bool hasReminderTimeReached() {
        // Transition logic for ReminderTimeReached
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasWheelMoved() {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseDebounceMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseDebounceMovement(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Filters out false movements to ensure accurate detection.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for DebounceMovement
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasReminderDebounceFailed()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new Reminding(machine)));
            return;
        }
        if (this->hasDebounceFailed()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new Idle(machine)));
            return;
        }
        if (this->hasDebouncePassed()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new CountMovement(machine)));
            return;
        }
    }

    virtual bool hasReminderDebounceFailed() {
        // Transition logic for ReminderDebounceFailed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasDebounceFailed() {
        // Transition logic for DebounceFailed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasDebouncePassed() {
        // Transition logic for DebouncePassed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseCountMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseCountMovement(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Counts valid movement events for processing.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for CountMovement
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasMovementCounted()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new WaitForMoreMovement(machine)));
            return;
        }
    }

    virtual bool hasMovementCounted() {
        // Transition logic for MovementCounted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseWaitForMoreMovement : public BaseState<MedReminderStateMachine> {
public:
    BaseWaitForMoreMovement(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Awaits additional movement to confirm or complete an action.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for WaitForMoreMovement
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasWheelMoved()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new CountMovement(machine)));
            return;
        }
        if (this->hasWheelNotMoved()) {
            machine->changeState(std::make_unique<BaseState<MedReminderStateMachine>>(new MovementDetected(machine)));
            return;
        }
    }

    virtual bool hasWheelMoved() {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasWheelNotMoved() {
        // Transition logic for WheelNotMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseMovementDetected : public BaseState<MedReminderStateMachine> {
public:
    BaseMovementDetected(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Detects confirmed movement, signaling a completed interaction.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for MovementDetected
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasMovementHandled()) {
            machine->changeState(std::make_unique<Idle>(machine));
            return;
        }
    }

    virtual bool hasMovementHandled() {
        // Transition logic for MovementHandled
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};