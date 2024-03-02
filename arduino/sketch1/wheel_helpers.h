#ifndef WHEEL_HELPERS_H
#define WHEEL_HELPERS_H

#include "Arduino.h"

// Function prototypes for wheel_helpers.cpp
void setupWheel();
void checkState();
bool movementDetected();
int getMovementCount();
bool detectWheelMovement();
int getIndex();
void clearMovement();
int wheel_index_helper(int leftSensor, int middleSensor, int rightSensor);
int determinePolarity(int sensorValue);

#endif