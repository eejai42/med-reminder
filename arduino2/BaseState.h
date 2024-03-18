#pragma once

template<typename MachineType>
class BaseState {
public:
    MachineType* machine;

    BaseState(MachineType* machine) : machine(machine) {}
    virtual ~BaseState() = default;

    virtual void onCheck() = 0; // called in the arduio loop

    virtual void onEnter() = 0; // called when the state is activated
    virtual void onExit() = 0; // called when the state is de-activated
};
