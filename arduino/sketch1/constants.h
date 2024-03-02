#ifndef CONSTANTS_H
#define CONSTANTS_H

// If you have any global includes, uncomment the following line
// #include "Arduino.h"

// Pin configurations
extern const int left_hall_sensor_pin;
extern const int middle_hall_sensor_pin;
extern const int right_hall_sensor_pin;
extern const int wheel_hall_sensor_pin;
extern const unsigned long debounceDelay; // Debounce delay in milliseconds

// Speaker pin configuration
extern const int speakerPin;

// Timing configurations
extern const unsigned long wheelTurnDebounceMs; // Debounce time for wheel turn detection
extern const unsigned long quickTurnThresholdMs; // Threshold for quick turn detection

// Start and end hours for day and night
extern const int morningStartHour;
extern const int eveningStartHour;

// Beep frequencies and durations
extern const int beepShortFrequency; // Frequency for short beep
extern const int beepLongFrequency; // Frequency for long beep
extern const int beepFrequencies[];
extern const int beepDurationsMs[];

extern const int beepShortDurationMs; // Duration for short beep
extern const int beepLongDurationMs; // Duration for long beep

// Initial beep count for alerts
extern const int initialBeepCount;

// Beep sequence settings
extern const int initialSequenceCount;
extern const int maxSequenceCount;

// Confirmation signals configuration
struct ConfirmationSignal {
  int beepId; // ID of the beep pattern
  int beepCount; // Number of beeps
  int sequenceCount; // How many times the sequence is repeated
};

// Example configuration for start and stop time set signals
extern const ConfirmationSignal startTimeSetSignal;
extern const ConfirmationSignal stopTimeSetSignal;

// Type of beep for confirmations
extern const int confirmationBeepType; // Assuming 1 corresponds to long beep

#endif
