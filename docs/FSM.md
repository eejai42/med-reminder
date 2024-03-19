[Full Readme](README.md)

### Movement State Machine (FSM)

![Diagram](state-machine-planttext.uml.png)

### States and Transitions

#### 1. Bootup
Initializes the system and prepares for operation.  



 - **➡ GatherReminders(`BootupCompleted`): ➡** Initializes the recording of the current time slice immediately after system startup.
#### 2. GatherReminders
Awaits the time for the first medication reminder.  


 - **⬅ Bootup(`BootupCompleted`): ⬅** Initializes the recording of the current time slice immediately after system startup.

 - **➡ SaveReminders(`GatheringRemindersCompleted`): ➡** Waits for the first medication reminder after the initial setup is completed..
#### 3. SaveReminders
Captures the current time as a reference point for tracking.  


 - **⬅ GatherReminders(`GatheringRemindersCompleted`): ⬅** Waits for the first medication reminder after the initial setup is completed..

 - **➡ Idle(`RemindersSaved`): ➡** Saves reminder times for future reference and then moves to Idle..
#### 4. Reminding



 - **⬅ Idle(`ReminderTimeReached`): ⬅** Alert periodically until the wheel next moves.
 - **⬅ DebounceMovement(`ReminderDebounceFailed`): ⬅** If the movement while reminding doesn't actually complete, keep reminding..

 - **➡ DebounceMovement(`WheelMoved`): ➡** Quite the reminder, when the wheel moves.
#### 5. Idle
The system is in a standby mode, waiting for interaction or the next event.  


 - **⬅ SaveReminders(`RemindersSaved`): ⬅** Saves reminder times for future reference and then moves to Idle..
 - **⬅ DebounceMovement(`DebounceFailed`): ⬅** Returns to idle on failing to validate the wheel movement (debouncing)..
 - **⬅ MovementDetected(`MovementHandled`): ⬅** Completes processing of movement and awaits further user interaction..

 - **➡ Reminding(`ReminderTimeReached`): ➡** Alert periodically until the wheel next moves.
 - **➡ DebounceMovement(`WheelMoved`): ➡** Filters out false wheel movements to prevent erroneous operations..
#### 6. DebounceMovement
Filters out false movements to ensure accurate detection.  


 - **⬅ Reminding(`WheelMoved`): ⬅** Quite the reminder, when the wheel moves.
 - **⬅ Idle(`WheelMoved`): ⬅** Filters out false wheel movements to prevent erroneous operations..

 - **➡ Reminding(`ReminderDebounceFailed`): ➡** If the movement while reminding doesn't actually complete, keep reminding..
 - **➡ Idle(`DebounceFailed`): ➡** Returns to idle on failing to validate the wheel movement (debouncing)..
 - **➡ MovementDetected(`DebouncePassed`): ➡** Counts validated wheel movement towards medication adherence tracking..
#### 7. MovementDetected
Detects confirmed movement, signaling a completed interaction.  


 - **⬅ DebounceMovement(`DebouncePassed`): ⬅** Counts validated wheel movement towards medication adherence tracking..

 - **➡ Idle(`MovementHandled`): ➡** Completes processing of movement and awaits further user interaction..


### Initial State
- **Idle**: The machine initializes in the Idle state, awaiting the first user interaction to begin the detection and handling process.

### Implementation Note
This state machine is crucial for ensuring the pillbox operates reliably, accurately tracking user interactions to maintain an up-to-date medication schedule. It effectively filters out accidental or irrelevant movements, focusing on intentional user actions to adjust the medication reminder timings. Through this mechanism, the Physical-Med-Reminder system provides a user-friendly and intuitive interface that requires minimal direct interaction, simplifying daily medication management.
