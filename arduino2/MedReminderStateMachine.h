#pragma once
// Adjusted StateMachine.h Template for MedReminderStateMachine
#pragma once

enum class State {
    Bootup,
    GatherReminders,
    SaveReminders,
    Reminding,
    Idle,
    DebounceMovement,
    CountMovement,
    WaitForMoreMovement,
    MovementDetected,
    // Add additional states here
};

class MedReminderStateMachine {
private:
    State currentState;

public:
    MedReminderStateMachine();
    void checkState();

    // State transition utility methods
    void transitionTo(State newState);
    void onExit(State state);
    void onEnter(State state);

    // Enter and Exit methods for Bootup state
    void enterBootup();
    void exitBootup();

    // Action handlers for the Bootup state
    bool hasBootup_BootupCompleted();
    // Enter and Exit methods for GatherReminders state
    void enterGatherReminders();
    void exitGatherReminders();

    // Action handlers for the GatherReminders state
    bool hasGatherReminders_GatheringRemindersCompleted();
    // Enter and Exit methods for SaveReminders state
    void enterSaveReminders();
    void exitSaveReminders();

    // Action handlers for the SaveReminders state
    bool hasSaveReminders_RemindersSaved();
    // Enter and Exit methods for Reminding state
    void enterReminding();
    void exitReminding();

    // Action handlers for the Reminding state
    bool hasReminding_WheelMoved();
    // Enter and Exit methods for Idle state
    void enterIdle();
    void exitIdle();

    // Action handlers for the Idle state
    bool hasIdle_ReminderTimeReached();
    bool hasIdle_WheelMoved();
    // Enter and Exit methods for DebounceMovement state
    void enterDebounceMovement();
    void exitDebounceMovement();

    // Action handlers for the DebounceMovement state
    bool hasDebounceMovement_ReminderDebounceFailed();
    bool hasDebounceMovement_DebounceFailed();
    bool hasDebounceMovement_DebouncePassed();
    // Enter and Exit methods for CountMovement state
    void enterCountMovement();
    void exitCountMovement();

    // Action handlers for the CountMovement state
    bool hasCountMovement_MovementCounted();
    // Enter and Exit methods for WaitForMoreMovement state
    void enterWaitForMoreMovement();
    void exitWaitForMoreMovement();

    // Action handlers for the WaitForMoreMovement state
    bool hasWaitForMoreMovement_WheelMoved();
    bool hasWaitForMoreMovement_WheelNotMoved();
    // Enter and Exit methods for MovementDetected state
    void enterMovementDetected();
    void exitMovementDetected();

    // Action handlers for the MovementDetected state
    bool hasMovementDetected_MovementHandled();
};

extern MedReminderStateMachine* stateMachine;