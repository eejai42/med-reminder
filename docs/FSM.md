[Full Readme](README.md)

### Movement State Machine (FSM)

![Diagram](state-machine-planttext.uml.png)

### States and Transitions

#### 1. Training
First day - it just counts when pills are taken


 - **⬅ TrainingMovement(`ReminderSaved`): ⬅** On training day, the reminder is saved, and returns to Training..

 - **➡ TrainingMovement(`MovementDetected`): ➡** On training day, movement saves the reminder.
 - **➡ Idle(`NewDay`): ➡** When the first 24 hours is reached, the system stops training, and moves into the idle state.
#### 2. TrainingMovement
When movement is detected during the first day, the reminder time is saved (relative to when the device was turned on)


 - **⬅ Training(`MovementDetected`): ⬅** On training day, movement saves the reminder.

 - **➡ Training(`ReminderSaved`): ➡** On training day, the reminder is saved, and returns to Training..
#### 3. Idle
This is the state that the device will spend most of it's time in, after training, but not while in the brief reminding/alerting phases.


 - **⬅ Training(`NewDay`): ⬅** When the first 24 hours is reached, the system stops training, and moves into the idle state.
 - **⬅ ClearReminder(`ReminderCleared`): ⬅** After the appropriate reminder has been cleared, go back to the idle state..

 - **➡ AboutToAlert(`WithinMSOfNextReminder`): ➡** Within, say, a configurable 10 minutes of the reminder, it will switch to an about to alert state, where it is not yet alerting, but will count any movement to clear the pills.
#### 4. AboutToAlert
When we are within a little bit of time of the reminder, any movement detected will clear the next reminder, but it will not start actively alerting yet


 - **⬅ Idle(`WithinMSOfNextReminder`): ⬅** Within, say, a configurable 10 minutes of the reminder, it will switch to an about to alert state, where it is not yet alerting, but will count any movement to clear the pills.

 - **➡ Alerting(`ReminderTimeReached`): ➡** If we are about  to alert, and the reminder time is reached, start alerting..
 - **➡ ClearReminder(`MovementDetected`): ➡** Movement in the about to alert state will move to clear the appropriate reminder..
#### 5. Alerting
When the actual alerting time is reached, it starts alerting.



 - **⬅ AboutToAlert(`ReminderTimeReached`): ⬅** If we are about  to alert, and the reminder time is reached, start alerting..

 - **➡ ClearReminder(`SystemButtonPushed`): ➡** While alerting, if the system button is pushed, move to clear the reminder..
 - **➡ ClearReminder(`MovementDetected`): ➡** While alerting, if movement is detected, go to clear the reminder..
#### 6. ClearReminder
In a variety of situations, the current (or next) reminder is cleared, and the state returns back to idle


 - **⬅ AboutToAlert(`MovementDetected`): ⬅** Movement in the about to alert state will move to clear the appropriate reminder..
 - **⬅ Alerting(`SystemButtonPushed`): ⬅** While alerting, if the system button is pushed, move to clear the reminder..
 - **⬅ Alerting(`MovementDetected`): ⬅** While alerting, if movement is detected, go to clear the reminder..

 - **➡ Idle(`ReminderCleared`): ➡** After the appropriate reminder has been cleared, go back to the idle state..


### Initial State
- **Idle**: The machine initializes in the Idle state, awaiting the first user interaction to begin the detection and handling process.

### Implementation Note
This state machine is crucial for ensuring the pillbox operates reliably, accurately tracking user interactions to maintain an up-to-date medication schedule. It effectively filters out accidental or irrelevant movements, focusing on intentional user actions to adjust the medication reminder timings. Through this mechanism, the Physical-Med-Reminder system provides a user-friendly and intuitive interface that requires minimal direct interaction, simplifying daily medication management.
