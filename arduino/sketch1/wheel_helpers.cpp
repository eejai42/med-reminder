#include "Arduino.h"
#include "constants.h"
#include "alarm_helpers.h"
#include "wheel_helpers.h"

// Define initial states and variables
State currentState = Idle;
int movement_count = 0;
int last_index = 0;  // Initialize to an impossible value for startup detection
int move_index = 0;  // The index of the slice when a move was first detected
int wheel_number = 0;
int last_wheel_number = 0;
int current_index = -1;
int is_am = -1;
int last_is_am = -1;
unsigned long lastDebounceTime = 0;

// Initial setup for wheel sensors
void setupWheel() {
  pinMode(bit2_hall_sensor_pin, INPUT_PULLUP);
  pinMode(bit1_hall_sensor_pin, INPUT_PULLUP);
  pinMode(am_hall_sensor_pin, INPUT_PULLUP);
  pinMode(wheel_hall_sensor_pin, INPUT_PULLUP);
}

int upToDown(int reading) {
  return reading == HIGH ? 0 : 1;
}


void checkDayTime() {

  // Read sensor values
  wheel_number = !digitalRead(wheel_hall_sensor_pin);

  is_am = upToDown(digitalRead(am_hall_sensor_pin));

  int bit1 = upToDown(digitalRead(bit1_hall_sensor_pin));
  int bit2 = upToDown(digitalRead(bit2_hall_sensor_pin));

  current_index = ((bit2 << 1) | (bit1)) + (wheel_number * 3) + 1;
}

int getIndex() {
  checkDayTime();

  // Convert sensor readings to binary index
  return  current_index;
}


DayTime getDayAndTime(bool isWheel1, int sliceIndex) {

  bool isWheel2 = !isWheel1;
  int localSlice = sliceIndex;

  DayTime result;
  result.isAM = is_am;
  result.dow = current_index;
  result.system_day = days_into_cycle();
  result.system_minutes = minutes_since_day_started();
  result.timer2_minutes = getTimer2Minutes();


  // if (isWheel1) Serial.print("Wheel 1: ");
  // else Serial.print("Wheel 2: ");
  // Serial.print(" - slice: ");
  // Serial.print(current_index);
  // Serial.print(" - local: ");
  // Serial.print(localSlice);
  // Serial.print(" -  ");
  // Serial.println(is_am ? "AM" : "PM");

  return result;
}

DayTime getDayAndTime() {
  return getDayAndTime(getWheelNumber() == 1, getIndex());
}

void printDowTod() {
  DayTime dt = getDayAndTime();
  Serial.print(dt.isAM ? " ^^^ Morning...  " : " ... Evening vvv  ");
  Serial.print("Day: ");
  Serial.println(dt.dow);
}

void printSystemTime() {
  DayTime dt = getDayAndTime();
  Serial.print("System Day: ");
  Serial.print(dt.system_day);
  Serial.print(" Min: ");
  Serial.print(dt.system_minutes);
  Serial.print(" T2: ");
  Serial.print(dt.timer2_minutes);
  Serial.print(" MS: ");
  Serial.println(millis() / msPerMinute);
}

void printMovement(int spotsMoved, int index, int wheelNumber) {
  Serial.print("SPOTS MOVED:");
  Serial.print(spotsMoved);
  Serial.print(" -> Current Slice: ");
  Serial.print(index);
  Serial.print(" -> WHEEL: ");
  Serial.println(wheelNumber);
  printSystemTime();
  printDowTod();
}

void printMovement() {
  int index = getIndex();
  int spotsMoved = getMovementCount();
  int wheelNumber = getWheelNumber();
  printMovement(spotsMoved, index, wheelNumber);
}

// Function to handle state transitions
void transitionTo(State newState) {
  // Serial.print("Transitioning from: ");
  // Serial.print(currentState);
  // Serial.print(" -> ");
  // Serial.println(newState);

  currentState = newState;
  switch (currentState) {
    case Idle:
      Serial.println(" -------------------------------------- IDLE ----------------------------------------");
      movement_count = 0;
      // Setup for Idle state
      break;
    case Debouncing:
      // Serial.print(" -------------------------------------- DEBOUNCEING ----------------------------------------");
      // Serial.println(movement_count);
      last_index = getIndex();
      last_wheel_number = wheel_number;
      lastDebounceTime = millis();
      break;
    case Count_Movement:
      movement_count++;
      //Serial.print(" -------------------------------------- COUNTING MOVEMENT ----------------------------------------");
      //Serial.println(movement_count);
      //move_index = last_index = getIndex();
      // More setup if necessary
      break;
    case Waiting_For_More_Movement:
      lastDebounceTime = millis();
      //Serial.println(" -------------------------------------- WAITING FOR MORE MOVEMENT ----------------------------------------");
      last_index == getIndex();
      //debounceTimer = millis();
      break;
    case Movement_Detected:
      //Serial.println(" -------------------------------------- Movement found ----------------------------------------");
      // Actions for movement detected
      break;
  }
}

// Function to check and update the state based on sensor readings
void checkState() {
  // Ensure we're constantly updating the index based on the current sensor state
  int index = getIndex();
  bool movement = detectWheelMovement();  // Check if the wheel has moved since the last reading

  if (currentState == Idle) {
    if (movement) {
      transitionTo(Debouncing);
    }
  } else if (currentState == Debouncing) {
    int elapsedTime = (millis() - lastDebounceTime);
    int index = getIndex();
    // Serial.print("Elapsed: ");
    // Serial.println(elapsedTime);
    if ((elapsedTime > wheelTurnDebounceMs)) {
      lastDebounceTime = millis();
      transitionTo(Count_Movement);
    } else {
      if (movement) {
        lastDebounceTime = millis();
        last_index = getIndex();
      }
      // Serial.print("Waiting for elapsed time to expire: ");
      // Serial.println(elapsedTime);
    }
  } else if (currentState == Count_Movement) {
    // Assuming movement count is handled here
    transitionTo(Waiting_For_More_Movement);
    //Serial.println(elapsedTime);
  } else if (currentState == Waiting_For_More_Movement) {
    if ((millis() - lastDebounceTime) > quickTurnThresholdMs) {
      transitionTo(Movement_Detected);
    }

    if (movement) {
      transitionTo(Debouncing);
    }
  } else if (currentState == Movement_Detected) {
    // do nothing until clearMovement() is called...
    // Serial.print("waiting for movement to be cleared() - spots: ");
    // Serial.println(movement_count);
  }
}

int getWheelNumber() {
  return wheel_number;
}

bool movementDetected() {
  return currentState == Movement_Detected;
}

int getMovementCount() {
  return movement_count;
}

bool detectWheelMovement() {
  int tempIndex = getIndex();  // Get the current index based on sensor values
  if (last_wheel_number != wheel_number) {
    return true;
  }

  if (last_is_am != is_am) {
    last_is_am = is_am;
    return true;
  }

  if (tempIndex != last_index) {  // Check if there's a change and it's not the initial setup
    move_index = tempIndex;  
    return true;
  }
  return false;
}

bool getIsAM() {
  return is_am;
}
void clearMovement() {
  //Serial.println("CLEARING MOVEMENT COUNT!");
  movement_count = 0;
  currentState = Idle;  // Reset to Idle after clearing movement
}

void printAndClearMovement() {
  int index = getIndex();
  int spotsMoved = getMovementCount();
  int wheelNumber = getWheelNumber();
  printMovement(spotsMoved, index, wheelNumber);
  // Handle wheel movement (e.g., update state, play confirmation beep)
  clearMovement();
  emitBeepSequence(80, spotsMoved);  // Example usage of emitBeepSequence
  delay(250);
  emitBeepSequence(80, index);  // Example usage of emitBeepSequence
  delay(250);
  emitBeepSequence(80, wheelNumber);  // Example usage of emitBeepSequence
}

