#include "Arduino.h"
#include "constants.h"
#include "wheel_helpers.h"

// referenced by main_loop.cpp

void setupWheel() {
  pinMode(left_hall_sensor_pin, INPUT);
  pinMode(middle_hall_sensor_pin, INPUT);
  pinMode(right_hall_sensor_pin, INPUT);
  pinMode(wheel_hall_sensor_pin, INPUT);
}

// Initial state
unsigned long debounceTimer = 0;

enum State {
    Idle,
    Debouncing,
    Count_Movement,
    Waiting_For_More_Movement,
    Movement_Detected
};

// Initial state
State currentState = Idle;
int movement_count = 0;
int last_index = -1; // Initialize to an impossible value for startup detection
int lastDebounceTime = 0;

void transitionTo(State newState) {
    currentState = newState;
    switch (currentState) {
        case Idle:
            // Setup for Idle state
            break;
        case Debouncing:
            debounceTimer = millis();
            break;
        case Count_Movement:
            movement_count++;
            // More setup if necessary
            break;
        case Waiting_For_More_Movement:
            debounceTimer = millis();
            break;
        case Movement_Detected:
            // Actions for movement detected
            break;
    }
}

void checkState() {
    int index = getIndex();
    switch (currentState) {
        case Idle:
            if (index != last_index) {
                transitionTo(Debouncing);
            }
            break;
        case Debouncing:
            if ((millis() - debounceTimer) > debounceDelay) {
                if (index != last_index) {
                    last_index = index;
                    transitionTo(Count_Movement);
                } else {
                    transitionTo(Idle);
                }
            }
            break;
        case Count_Movement:
            transitionTo(Waiting_For_More_Movement);
            break;
        case Waiting_For_More_Movement:
            if ((millis() - debounceTimer) > debounceDelay) {
                if (index != last_index) {
                    last_index = index;
                    transitionTo(Count_Movement);
                } else {
                    transitionTo(Movement_Detected);
                }
            }
            break;
        case Movement_Detected:
            // Implement the logic to handle movement detected
            // For example, reset movement count, perform an action, etc.
            break;
    }
}

bool movementDetected() {
  return currentState == Movement_Detected;
}

int getMovementCount() {
  return movement_count;
}

bool detectWheelMovement() {
  int leftSensor = digitalRead(left_hall_sensor_pin);
  int middleSensor = digitalRead(middle_hall_sensor_pin);
  int rightSensor = digitalRead(right_hall_sensor_pin);
  int index = wheel_index_helper(leftSensor, middleSensor, rightSensor);
  if (index != last_index) {
    lastDebounceTime = millis();
    last_index = index;
    return true;
  }
  return false;
}

int getIndex() {
  // Example implementation. Adapt based on your actual sensor setup and index determination logic.
  int leftSensor = digitalRead(left_hall_sensor_pin);
  int middleSensor = digitalRead(middle_hall_sensor_pin);
  int rightSensor = digitalRead(right_hall_sensor_pin);
  return wheel_index_helper(leftSensor, middleSensor, rightSensor);
}

void clearMovement() {
  movement_count = 0;
  currentState = Idle;
}


int wheel_index_helper(int leftSensor, int middleSensor, int rightSensor) {
  // Implement based on your specific logic for determining wheel index
  // This is a placeholder function. Update it according to your binary slice ID detection logic.
  return (leftSensor << 2) | (middleSensor << 1) | rightSensor;
}

int determinePolarity(int sensorValue) {
  // Example function to determine polarity. Adjust according to your needs.
  return sensorValue > 512 ? HIGH : LOW;
}