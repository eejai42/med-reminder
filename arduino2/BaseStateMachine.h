#pragma once
#include <memory>

// Forward declaration of BaseState to avoid circular dependency.
class BaseState;

class BaseStateMachine {
protected:
    std::unique_ptr<BaseState> currentState;

public:
    BaseStateMachine();
    virtual ~BaseStateMachine();

    void changeState(std::unique_ptr<BaseState> newState);
    void checkState();
};