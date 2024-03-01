// constants.cpp
#include "Arduino.h"

const int left_hall_sensor_pin = 2;
const int middle_hall_sensor_pin = 3;
const int right_hall_sensor_pin = 4;
const int wheel_hall_sensor_pin = 6;
const unsigned long debounceDelay = 500; // Debounce delay in milliseconds

// Movement state machine variables
enum State { Idle, Debouncing, Movement_Counting, Movement_Detected };
State currentState = Idle;
unsigned long lastDebounceTime = 0;
int last_index = -1;
int movement_count = 0;

// Speaker pin configuration
const int speakerPin = 9;

// Timing configurations
const unsigned long wheelTurnDebounceMs = 500; // Debounce time for wheel turn detection
const unsigned long quickTurnThresholdMs = 10000; // Threshold for quick turn detection

// Start and end hours for day and night
const int morningStartHour = 6;
const int eveningStartHour = 18;

// Snooze interval minutes
const int snoozeIntervalMinutes[] = {5, 10, 15};

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

// Confirmation signals configuration
// Start and stop time set signals
struct ConfirmationSignal {
  int beepId; // ID of the beep pattern
  int beepCount; // Number of beeps
  int sequenceCount; // How many times the sequence is repeated
};

// Assuming beepId 0 corresponds to a predefined beep pattern
const ConfirmationSignal startTimeSetSignal = {0, 1, 1}; // Example configuration
const ConfirmationSignal stopTimeSetSignal = {0, 1, 1}; // Example configuration

// Type of beep for confirmations (0 for short, 1 for long, based on your beep frequencies)
const int confirmationBeepType = 1; // Assuming 1 corresponds to long beep