[Full Readme](README.md)

### Movement State Machine (FSM)

![Diagram](state-machine-planttext.uml.png)

### States and Transitions

#### 1. Training
First day - it just counts when pills are taken

 - **`Training .`**_`MovementDetected`_**`( ➡ SavingReminder )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">On training day, movement saves the reminder.<br /> <span>
 - **`Training .`**_`NewDay`_**`( ➡ Idle )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">When the first 24 hours is reached, the system stops training, and moves into the idle state.<br /> <span>
---------
 - **`SavingReminder .`**_`ReminderSaved`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">On training day, the reminder is saved, and returns to Training.<span>
 - **`Alerting .`**_`MainInputDoubleClicked`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">If the button is ever double  licked, reset the box<span>

#### 2. SavingReminder
When movement is detected during the first day, the reminder time is saved (relative to when the device was turned on)

 - **`SavingReminder .`**_`ReminderSaved`_**`( ➡ Training )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">On training day, the reminder is saved, and returns to Training..<br /> <span>
---------
 - **`Training .`**_`MovementDetected`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">On training day, movement saves the reminder<span>

#### 3. Idle
This is the state that the device will spend most of it's time in, after training, but not while in the brief reminding/alerting phases.

 - **`Idle .`**_`WithinMSOfNextReminder`_**`( ➡ AboutToAlert )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">Within, say, a configurable 10 minutes of the reminder, it will switch to an about to alert state, where it is not yet alerting, but will count any movement to clear the pills.<br /> <span>
---------
 - **`Training .`**_`NewDay`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">When the first 24 hours is reached, the system stops training, and moves into the idle state<span>
 - **`ClearReminder .`**_`ReminderCleared`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">After the appropriate reminder has been cleared, go back to the idle state.<span>

#### 4. AboutToAlert
When we are within a little bit of time of the reminder, any movement detected will clear the next reminder, but it will not start actively alerting yet

 - **`AboutToAlert .`**_`ReminderTimeReached`_**`( ➡ Alerting )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">If we are about  to alert, and the reminder time is reached, start alerting..<br /> <span>
 - **`AboutToAlert .`**_`MovementDetected`_**`( ➡ ClearReminder )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">Movement in the about to alert state will move to clear the appropriate reminder..<br /> <span>
---------
 - **`Idle .`**_`WithinMSOfNextReminder`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">Within, say, a configurable 10 minutes of the reminder, it will switch to an about to alert state, where it is not yet alerting, but will count any movement to clear the pills<span>

#### 5. Alerting
When the actual alerting time is reached, it starts alerting.


 - **`Alerting .`**_`MainInputDoubleClicked`_**`( ➡ Training )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">If the button is ever double  licked, reset the box.<br /> <span>
 - **`Alerting .`**_`SystemButtonPushed`_**`( ➡ ClearReminder )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">While alerting, if the system button is pushed, move to clear the reminder..<br /> <span>
 - **`Alerting .`**_`MovementDetected`_**`( ➡ ClearReminder )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">While alerting, if movement is detected, go to clear the reminder..<br /> <span>
---------
 - **`AboutToAlert .`**_`ReminderTimeReached`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">If we are about  to alert, and the reminder time is reached, start alerting.<span>

#### 6. ClearReminder
In a variety of situations, the current (or next) reminder is cleared, and the state returns back to idle

 - **`ClearReminder .`**_`ReminderCleared`_**`( ➡ Idle )`:** 
 <span style="font-size: 1em; margin-bottom: 0.75em; color: green;">After the appropriate reminder has been cleared, go back to the idle state..<br /> <span>
---------
 - **`AboutToAlert .`**_`MovementDetected`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">Movement in the about to alert state will move to clear the appropriate reminder.<span>
 - **`Alerting .`**_`SystemButtonPushed`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">While alerting, if the system button is pushed, move to clear the reminder.<span>
 - **`Alerting .`**_`MovementDetected`_**`( this )`:** 
 <span style="font-size: 0.8em; padding-bottom: 0.25em; color: darkgray;">While alerting, if movement is detected, go to clear the reminder.<span>

### Initial State
- **Idle**: The machine initializes in the Idle state, awaiting the first user interaction to begin the detection and handling process.

### Implementation Note
This state machine is crucial for ensuring the pillbox operates reliably, accurately tracking user interactions to maintain an up-to-date medication schedule. It effectively filters out accidental or irrelevant movements, focusing on intentional user actions to adjust the medication reminder timings. Through this mechanism, the Physical-Med-Reminder system provides a user-friendly and intuitive interface that requires minimal direct interaction, simplifying daily medication management.
