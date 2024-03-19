#pragma once
#include "BaseStateMachine.h"
#include "BaseState.h" // Include here to have the complete type for BaseState.

BaseStateMachine::BaseStateMachine() = default;

BaseStateMachine::~BaseStateMachine() = default;

void BaseStateMachine::changeState(std::unique_ptr<BaseState> newState) {
    if (currentState) {
        currentState->onExit();
    }
    currentState = std::move(newState);
    if (currentState) {
        currentState->onEnter();
    }
}

void BaseStateMachine::checkState() {
    if (currentState) {
        currentState->onCheck();
    }
}
