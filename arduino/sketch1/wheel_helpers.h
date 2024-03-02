#ifndef WHEEL_HELPERS_H
#define WHEEL_HELPERS_H

#include "Arduino.h"

// Function prototypes for wheel_helpers.cpp
void setupWheel(); // configuration
void checkState(); // check the current state of the system.
bool movementDetected(); // return true if movement has been recorded
int getMovementCount(); // returns the count of how many steps were taken
void clearMovement(); // Clear the count and return to idling

bool detectWheelMovement(); // Check if the wheel has moved
int getIndex(); // Get the index of the current slice
int wheel_index_helper(int leftSensor, int middleSensor, int rightSensor); // figure out the index based on the 
int determinePolarity(int sensorValue); // check if a sensor is triggered

#endif