#include "Arduino.h"
#include "constants.cpp"

// referenced by main_loop.cpp

// Function prototypes
void checkState();
bool movementDetected();
int getMovementCount();
bool detectWheelMovement();
int getIndex();
void clearMovement();
int wheel_index_helper(int leftSensor, int middleSensor, int rightSensor);
int determinePolarity(int sensorValue);

void setupWheel() {
  pinMode(left_hall_sensor_pin, INPUT);
  pinMode(middle_hall_sensor_pin, INPUT);
  pinMode(right_hall_sensor_pin, INPUT);
  pinMode(wheel_hall_sensor_pin, INPUT);
}

void checkState() {
  switch (currentState) {
    case Idle:
      if (detectWheelMovement()) {
        currentState = Debouncing;
      }
      break;
    case Debouncing:
      if (millis() - lastDebounceTime > debounceDelay) {
        currentState = Movement_Counting;
        movement_count++;
      }
      break;
    case Movement_Counting:
      if (!detectWheelMovement()) {
        currentState = Movement_Detected;
      }
      break;
    case Movement_Detected:
      Serial.print("Movement detected: ");
      Serial.println(movement_count);
      clearMovement();
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