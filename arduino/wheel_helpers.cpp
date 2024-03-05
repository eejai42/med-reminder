#include "Arduino.h"
#include "constants.h"
#include "alarm_helpers.h"
#include "wheel_helpers.h"

// Define initial states and variables
State currentState = Idle;
int movement_count = 0;
int last_index = 0;  // Initialize to an impossible value for startup detection
int move_index = 0;  // The index of the slice when a move was first detected
int last_is_am = -1;
int wheel_number = 0;
int last_wheel_number = 0;
int current_index = -1;
unsigned long lastDebounceTime = 0;

// Initial setup for wheel sensors
void setupWheel() {
  pinMode(bit1_hall_sensor_pin, INPUT_PULLUP);
  pinMode(bit2_hall_sensor_pin, INPUT_PULLUP);
  pinMode(am_hall_sensor_pin, INPUT_PULLUP);
  pinMode(wheel_hall_sensor_pin, INPUT_PULLUP);

  pinMode(bit1_hall_led_pin, OUTPUT);
  pinMode(bit2_hall_led_pin, OUTPUT);
  pinMode(am_hall_led_pin, OUTPUT);
  pinMode(wheel_hall_led_pin, OUTPUT);
}

int upToDown(int reading) {
  return reading == HIGH ? 0 : 1;
}


void checkDayTime() {

  // Read sensor values
  wheel_number = !digitalRead(wheel_hall_sensor_pin);
  digitalWrite(wheel_hall_led_pin, wheel_number ? HIGH : LOW);

  bool isAM = !upToDown(digitalRead(am_hall_sensor_pin));
  digitalWrite(am_hall_led_pin, isAM ? LOW : HIGH);
  setIsAM(isAM);

  int bit1 = upToDown(digitalRead(bit1_hall_sensor_pin));
  int bit2 = upToDown(digitalRead(bit2_hall_sensor_pin));
  digitalWrite(bit1_hall_led_pin, bit1 ? HIGH : LOW);
  digitalWrite(bit2_hall_led_pin, bit2 ? HIGH : LOW);

  current_index = ((bit2 << 1) | (bit1)) + (wheel_number * 3) + 1;
}

int getIndex() {
  checkDayTime();

  // Convert sensor readings to binary index
  return current_index;
}



void printMovement(int spotsMoved, int index, int wheelNumber) {
  // Serial.print("SPOTS MOVED:");
  // Serial.print(spotsMoved);
  // Serial.print(" -> Current Slice: ");
  // Serial.print(index);
  // Serial.print(" -> WHEEL: ");
  // Serial.println(wheelNumber);
  printSystemTime();
  // printDowTod();
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

  bool movement = false;
  if (millis() > 10000) {
    movement = detectWheelMovement();  // Check if the wheel has moved since the last reading
  }


  if (currentState == Idle) {
    if (movement) {
      if (millis() < 10000) {
        clearMovement();
      } else {
        transitionTo(Debouncing);
      }
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

  bool isAM = getIsAM();
  if (last_is_am != isAM) {
    //Serial.println("                                                                   AM CHANGE DETECTED");
    last_is_am = isAM;
    return true;
  }

  if (tempIndex != last_index) {  // Check if there's a change and it's not the initial setup
    move_index = tempIndex;
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
  printMovement(spotsMoved, index, wheelNumber);
  // Handle wheel movement (e.g., update state, play confirmation beep)
  clearMovement();
  emitBeepSequence(400, 3);  // Example usage of emitBeepSequence
}
