#pragma once
#include <memory>
#include "BaseState.h"

template <typename StateType>
class BaseStateMachine
{
protected:
    std::unique_ptr<StateType> currentState;


public:
    BaseStateMachine() = default;
    virtual ~BaseStateMachine() = default;

    void changeState(std::unique_ptr<StateType> newState)
    {
        if (currentState)
        {
            currentState->onExit();
        }
        currentState = std::move(newState);
        if (currentState)
        {
            currentState->onEnter();
        }
    }


    void checkState() {
        if (currentState)
        {
            currentState->onCheck();
        }
    }
};