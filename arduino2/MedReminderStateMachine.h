#pragma once
#include "BaseState.h"
#include "BaseStateMachine.h"
#include <memory>
#include <iostream>
#include "Bootup.h"
#include "GatherReminders.h"
#include "SaveReminders.h"
#include "Idle.h"
#include "DebounceMovement.h"
#include "CountMovement.h"
#include "WaitForMoreMovement.h"
#include "MovementDetected.h"
#include "WaitForCommands.h"
#include "AdvanceCurrentReminder.h"
#include "SetExpectedReminder.h"
#include "Reboot.h"

// ***************************************************************
// Generated State Machine Classes for MedReminder project
// ***************************************************************

class MedReminderStateMachine : public BaseStateMachine<BaseState<MedReminderStateMachine>> {
public:
    MedReminderStateMachine() : BaseStateMachine() {
        // Initialize the machine with the Bootup state
        changeState(std::make_unique<Bootup>(this));
    }
};

class BaseBootup : public BaseState<MedReminderStateMachine> {
public:
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
            machine->changeState(std::make_unique<GatherReminders>(machine));
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
        if (this->hasRemindersGathered()) {
            machine->changeState(std::make_unique<SaveReminders>(machine));
            return;
        }
    }

    virtual bool hasRemindersGathered() {
        // Transition logic for RemindersGathered
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
            machine->changeState(std::make_unique<Idle>(machine));
            return;
        }
    }

    virtual bool hasRemindersSaved() {
        // Transition logic for RemindersSaved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseIdle : public BaseState<MedReminderStateMachine> {
public:
    BaseIdle(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "The system is in a standby mode, waiting for interaction or the next event.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for Idle
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasWheelMoved()) {
            machine->changeState(std::make_unique<DebounceMovement>(machine));
            return;
        }
        if (this->hasMainInputClicked()) {
            machine->changeState(std::make_unique<WaitForCommands>(machine));
            return;
        }
    }

    virtual bool hasWheelMoved() {
        // Transition logic for WheelMoved
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasMainInputClicked() {
        // Transition logic for MainInputClicked
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
        if (this->hasDebouncePassed()) {
            machine->changeState(std::make_unique<CountMovement>(machine));
            return;
        }
        if (this->hasDebounceFailed()) {
            machine->changeState(std::make_unique<Idle>(machine));
            return;
        }
    }

    virtual bool hasDebouncePassed() {
        // Transition logic for DebouncePassed
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasDebounceFailed() {
        // Transition logic for DebounceFailed
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
            machine->changeState(std::make_unique<WaitForMoreMovement>(machine));
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
            machine->changeState(std::make_unique<CountMovement>(machine));
            return;
        }
        if (this->hasWheelNotMoved()) {
            machine->changeState(std::make_unique<MovementDetected>(machine));
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

class BaseWaitForCommands : public BaseState<MedReminderStateMachine> {
public:
    BaseWaitForCommands(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Enters a mode waiting for user commands through the main interface.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for WaitForCommands
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasMainInputDoubleClicked()) {
            machine->changeState(std::make_unique<SetExpectedReminder>(machine));
            return;
        }
        if (this->hasMainInputClicked()) {
            machine->changeState(std::make_unique<AdvanceCurrentReminder>(machine));
            return;
        }
        if (this->hasMainInputHeld()) {
            machine->changeState(std::make_unique<Reboot>(machine));
            return;
        }
    }

    virtual bool hasMainInputDoubleClicked() {
        // Transition logic for MainInputDoubleClicked
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasMainInputClicked() {
        // Transition logic for MainInputClicked
        return false; // Placeholder for actual condition that will be provided in derived class
    }
    virtual bool hasMainInputHeld() {
        // Transition logic for MainInputHeld
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseAdvanceCurrentReminder : public BaseState<MedReminderStateMachine> {
public:
    BaseAdvanceCurrentReminder(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Advances the medication reminder to the next scheduled time.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for AdvanceCurrentReminder
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasCurrentReminderAdvanced()) {
            machine->changeState(std::make_unique<Idle>(machine));
            return;
        }
    }

    virtual bool hasCurrentReminderAdvanced() {
        // Transition logic for CurrentReminderAdvanced
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseSetExpectedReminder : public BaseState<MedReminderStateMachine> {
public:
    BaseSetExpectedReminder(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Enables setting a new time for the next medication reminder.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for SetExpectedReminder
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasExpectedReminderSet()) {
            machine->changeState(std::make_unique<Idle>(machine));
            return;
        }
    }

    virtual bool hasExpectedReminderSet() {
        // Transition logic for ExpectedReminderSet
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};

class BaseReboot : public BaseState<MedReminderStateMachine> {
public:
    BaseReboot(MedReminderStateMachine* machine) : BaseState(machine) {}

    void onEnter() override {
        std::cout << "Reinitializes the system, effectively restarting it.  " << std::endl;
    }

    void onExit() override {
        // Custom exit logic for Reboot
    }

    void onCheck() override {
        // Handle transitions
        if (this->hasRebootStarted()) {
            machine->changeState(std::make_unique<Bootup>(machine));
            return;
        }
    }

    virtual bool hasRebootStarted() {
        // Transition logic for RebootStarted
        return false; // Placeholder for actual condition that will be provided in derived class
    }
};