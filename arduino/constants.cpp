// constants.cpp
// #include "Arduino.h"
#include "constants.h"


// Speaker pin configuration
const int ledPin = 2;
const int speakerPin = 8;

const int wheel_hall_sensor_pin = 13;
const int am_hall_sensor_pin = 10;
const int bit1_hall_sensor_pin = 11;
const int bit2_hall_sensor_pin = 12;


const int am_hall_led_pin = 7;
const int bit1_hall_led_pin = 6;
const int bit2_hall_led_pin = 5;
const int wheel_hall_led_pin = 4;


const unsigned long debounceDelay = 500; // Debounce delay in milliseconds

// Timing configurations
const unsigned long wheelTurnDebounceMs = 150; // Debounce time for wheel turn detection
const unsigned long quickTurnThresholdMs = 300; // Threshold for quick turn detection

const unsigned int minutesPerDay = 8;
const unsigned long msPerMinute = 6000;

extern const int initial_reminder_delay_seconds = 2;
extern const int initial_times_to_beep = 5;
extern const int msBetweenBeeps = 85;

