// constants.cpp
// #include "Arduino.h"
#include "constants.h"


// Speaker pin configuration
const int speakerPin = 13;

const int wheel_hall_sensor_pin = 2;

const int bit1_hall_sensor_pin = 10;
const int bit2_hall_sensor_pin = 11;
const int am_hall_sensor_pin = 12;

const unsigned long debounceDelay = 500; // Debounce delay in milliseconds

const unsigned long msPerMinute = 5000;
const int minutesPerDay = 5;
// Timing configurations
const unsigned long wheelTurnDebounceMs = 150; // Debounce time for wheel turn detection
const unsigned long quickTurnThresholdMs = 300; // Threshold for quick turn detection

// Snooze interval minutes
const int snoozeIntervalMinutes = 5;

// Beep frequencies and durations
const int beepShortFrequency = 1000; // Frequency for short beep
const int beepLongFrequency = 500; // Frequency for long beep
const int beepFrequencies[] = {1000, 1500}; // Frequencies for ascending beep sequence
const int beepDurationsMs[] = {1000, 1500}; // Frequencies for ascending beep sequence

const int beepShortDurationMs = 100; // Duration for short beep
const int beepLongDurationMs = 500; // Duration for long beep

// Initial beep count for alerts
const int initialBeepCount = 1;

// Beep sequence settings
const int initialSequenceCount = 1;
const int maxSequenceCount = 5;


// Assuming beepId 0 corresponds to a predefined beep pattern
const ConfirmationSignal startTimeSetSignal = {0, 1, 1}; // Example configuration
const ConfirmationSignal stopTimeSetSignal = {0, 1, 1}; // Example configuration

// Type of beep for confirmations (0 for short, 1 for long, based on your beep frequencies)
const int confirmationBeepType = 1; // Assuming 1 corresponds to long beep
