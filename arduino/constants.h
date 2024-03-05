#ifndef CONSTANTS_H
#define CONSTANTS_H

// If you have any global includes, uncomment the following line
// #include "Arduino.h"

// Pin configurations
extern const int wheel_hall_sensor_pin;
extern const int bit1_hall_sensor_pin;
extern const int bit2_hall_sensor_pin;
extern const int am_hall_sensor_pin;
extern const unsigned long debounceDelay; // Debounce delay in milliseconds
extern const int wheel_hall_led_pin;
extern const int bit1_hall_led_pin;
extern const int bit2_hall_led_pin;
extern const int am_hall_led_pin;

// Speaker pin configuration
extern const int ledPin;
extern const int speakerPin;

extern unsigned const int minutesPerDay;
extern unsigned const  long msPerMinute;

// Timing configurations
extern const unsigned long wheelTurnDebounceMs; // Debounce time for wheel turn detection
extern const unsigned long quickTurnThresholdMs; // Threshold for quick turn detection

// Initial beep count for alerts
extern const int initial_reminder_delay_seconds;
extern const int initial_times_to_beep;
extern const int msBetweenBeeps;

// Beep sequence settings
extern const int initialSequenceCount;
extern const int maxSequenceCount;

#endif
