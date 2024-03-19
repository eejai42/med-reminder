#include "MedReminderStateMachine.h"
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
// Implementation for MedReminderStateMachine and base state classes
// ***************************************************************

MedReminderStateMachine::MedReminderStateMachine() : BaseStateMachine() {
    // Constructor implementation
    // Example: changeState(std::make_unique<>(this));
}

void BaseBootup::onCheck() {
    // Handle transitions
    if (this->hasBootupCompleted()) {
        machine->changeState(std::make_unique<GatherReminders>(machine));
        return;
    }
}
void BaseGatherReminders::onCheck() {
    // Handle transitions
    if (this->hasGatheringRemindersCompleted()) {
        machine->changeState(std::make_unique<SaveReminders>(machine));
        return;
    }
}
void BaseSaveReminders::onCheck() {
    // Handle transitions
    if (this->hasRemindersSaved()) {
        machine->changeState(std::make_unique<Idle>(machine));
        return;
    }
}
void BaseReminding::onCheck() {
    // Handle transitions
    if (this->hasWheelMoved()) {
        machine->changeState(std::make_unique<DebounceMovement>(machine));
        return;
    }
}
void BaseIdle::onCheck() {
    // Handle transitions
    if (this->hasReminderTimeReached()) {
        machine->changeState(std::make_unique<Reminding>(machine));
        return;
    }
    if (this->hasWheelMoved()) {
        machine->changeState(std::make_unique<DebounceMovement>(machine));
        return;
    }
}
void BaseDebounceMovement::onCheck() {
    // Handle transitions
    if (this->hasReminderDebounceFailed()) {
        machine->changeState(std::make_unique<Reminding>(machine));
        return;
    }
    if (this->hasDebounceFailed()) {
        machine->changeState(std::make_unique<Idle>(machine));
        return;
    }
    if (this->hasDebouncePassed()) {
        machine->changeState(std::make_unique<CountMovement>(machine));
        return;
    }
}
void BaseCountMovement::onCheck() {
    // Handle transitions
    if (this->hasMovementCounted()) {
        machine->changeState(std::make_unique<WaitForMoreMovement>(machine));
        return;
    }
}
void BaseWaitForMoreMovement::onCheck() {
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
void BaseMovementDetected::onCheck() {
    // Handle transitions
    if (this->hasMovementHandled()) {
        machine->changeState(std::make_unique<Idle>(machine));
        return;
    }
}