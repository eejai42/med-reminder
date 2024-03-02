#include "Arduino.h"
#include "constants.h"
#include "beep_helpers.h"
#include "wheel_helpers.h"

// Define initial states and variables
State currentState = Idle;
int movement_count = 0;
int last_index = 0;  // Initialize to an impossible value for startup detection
int move_index = 0;  // The index of the slice when a move was first detected
int wheel_number = 0;
unsigned long lastDebounceTime = 0;

// Initial setup for wheel sensors
void setupWheel() {
  pinMode(left_hall_sensor_pin, INPUT_PULLUP);
  pinMode(middle_hall_sensor_pin, INPUT_PULLUP);
  pinMode(right_hall_sensor_pin, INPUT_PULLUP);
  pinMode(wheel_hall_sensor_pin, INPUT_PULLUP);
}

int upToDown(int reading) {
  return reading == HIGH ? 0 : 1;
}

int getIndex() {
  // Read sensor values
  int leftSensor = digitalRead(left_hall_sensor_pin);
  int middleSensor = digitalRead(middle_hall_sensor_pin);
  int rightSensor = digitalRead(right_hall_sensor_pin);

  wheel_number = digitalRead(wheel_hall_sensor_pin);


  // Convert sensor readings to binary index
  return (upToDown(leftSensor) << 2) | (upToDown(middleSensor) << 1) | (upToDown(rightSensor));
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
      Serial.print(" -------------------------------------- DEBOUNCEING ----------------------------------------");
      Serial.println(movement_count);
      last_index = getIndex();
      lastDebounceTime = millis();
      break;
    case Count_Movement:
      movement_count++;
      Serial.print(" -------------------------------------- COUNTING MOVEMENT ----------------------------------------");
      Serial.println(movement_count);
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
  return !(wheel_number) + 1;
}

bool movementDetected() {
  return currentState == Movement_Detected;
}

int getMovementCount() {
  return movement_count;
}

bool detectWheelMovement() {
  int current_index = getIndex();  // Get the current index based on sensor values

  if (current_index != last_index) {  // Check if there's a change and it's not the initial setup
    move_index = current_index;
    return true;
  }
  return false;
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
  Serial.print("SPOTS MOVED:");
  Serial.print(spotsMoved);
  Serial.print(" -> Current Slice: ");
  Serial.print(index);
  Serial.print(" -> WHEEL: ");
  Serial.println(wheelNumber);
  Serial.println();
  // Handle wheel movement (e.g., update state, play confirmation beep)
  clearMovement();
  emitBeepSequence(250, spotsMoved);  // Example usage of emitBeepSequence
  delay(1000);
  emitBeepSequence(250, index);  // Example usage of emitBeepSequence
  delay(1000);

  emitBeepSequence(250, wheelNumber);  // Example usage of emitBeepSequence
}
