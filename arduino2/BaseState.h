#pragma once
#include "BaseStateMachine.h"

class BaseState {
public:
    BaseStateMachine* machine;

    BaseState(BaseStateMachine* machine) : machine(machine) {}
    virtual ~BaseState() = default;

    virtual void onCheck() = 0; // called in the arduio loop

    virtual void onEnter() = 0; // called when the state is activated
    virtual void onExit() = 0; // called when the state is de-activated
};