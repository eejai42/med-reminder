// constants.cpp
// #include "Arduino.h"
#include "constants.h"
#define DEBUG;

// Speaker pin configuration
const int ledPin = 13;

const int wheel_hall_sensor_pin = 10;
const int wheel_hall_led_pin = 9;
const int am_hall_sensor_pin = 8;
const int am_hall_led_pin = 7;
const int bit1_hall_sensor_pin = 6;
const int bit1_hall_led_pin = 5;
const int bit2_hall_sensor_pin = 4;
const int bit2_hall_led_pin = 3;
const int speakerPin = 2;


const unsigned long debounceDelay = 500; // Debounce delay in milliseconds

// Timing configurations
const unsigned long wheelTurnDebounceMs = 150; // Debounce time for wheel turn detection
const unsigned long quickTurnThresholdMs = 300; // Threshold for quick turn detection

#ifdef DEBUG
const unsigned int minutesPerDay = 4;
const unsigned long msPerMinute = 8000;
#else
const unsigned int minutesPerDay = 1440;
const unsigned long msPerMinute = 60000;
#endif

extern const int initial_reminder_delay_seconds = 2;
extern const int initial_times_to_beep = 5;
extern const int msBetweenBeeps = 85;

