#include "MedReminderStateMachine.h"
#include <iostream>
#include "Training.h"
#include "TrainingMovement.h"
#include "Idle.h"
#include "AboutToAlert.h"
#include "Alerting.h"
#include "ClearReminder.h"

// ***************************************************************
// Implementation for MedReminderStateMachine and base state classes
// ***************************************************************

MedReminderStateMachine::MedReminderStateMachine() : BaseStateMachine() {
    // Constructor implementation
    // Example: changeState(std::make_unique<>(this));
}

void BaseTraining::onCheck() {
    // Handle transitions
    if (this->hasMovementDetected()) {
        machine->changeState(std::make_unique<TrainingMovement>(machine));
        return;
    }
    if (this->hasNewDay()) {
        machine->changeState(std::make_unique<Idle>(machine));
        return;
    }
}
void BaseTrainingMovement::onCheck() {
    // Handle transitions
    if (this->hasReminderSaved()) {
        machine->changeState(std::make_unique<Training>(machine));
        return;
    }
}
void BaseIdle::onCheck() {
    // Handle transitions
    if (this->hasWithinMSOfNextReminder()) {
        machine->changeState(std::make_unique<AboutToAlert>(machine));
        return;
    }
}
void BaseAboutToAlert::onCheck() {
    // Handle transitions
    if (this->hasReminderTimeReached()) {
        machine->changeState(std::make_unique<Alerting>(machine));
        return;
    }
    if (this->hasMovementDetected()) {
        machine->changeState(std::make_unique<ClearReminder>(machine));
        return;
    }
}
void BaseAlerting::onCheck() {
    // Handle transitions
    if (this->hasSystemButtonPushed()) {
        machine->changeState(std::make_unique<ClearReminder>(machine));
        return;
    }
    if (this->hasMovementDetected()) {
        machine->changeState(std::make_unique<ClearReminder>(machine));
        return;
    }
}
void BaseClearReminder::onCheck() {
    // Handle transitions
    if (this->hasReminderCleared()) {
        machine->changeState(std::make_unique<Idle>(machine));
        return;
    }
}