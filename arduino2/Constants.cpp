#pragma once
/* Project Constants
 ************  NOTE! This file is derived using Handlebars 
 ************  Source model json in /SSoT/ folder
 ************  ssotme json-hbars-transform -i /SSoT/source-data.json -i constants.hbars -o ../constants.cpp
 ************  ssotme json-hbars-transform -i /SSoT/source-data.json -i constantHeaders.hbars -o ../constants.h
*/
#include "Constants.h"




// *** Debouncing constants **
const unsigned long debounce_delay = 500; // Debounce delay in milliseconds
const unsigned long wheel_turn_debounce_ms = 150; // Debounce time for wheel turn detection
const unsigned long quick_turn_threshold_ms = 300; // Threshold for quick turn detection

// *** Parts constants **
const unsigned int status_beeps_speaker = 2; // The status_beeps_speaker wire connects Pin-2 to a speaker emitting auditory beeps for status alerts in an orange color.
const unsigned int bit1_status_led = 3; // The bit1_status_led wire runs from Pin-3 to a white LED indicating the status of the first bit for medication timing.
const unsigned int sense_bit1_hall_effect_sensor = 4; // Connecting Pin-4 to a white Hall Effect Sensor, the sense_bit1_hall_effect_sensor wire senses the first bit's magnetic field change.
const unsigned int latch_bit1_latching_switch = 4; // The latch_bit1_latching_switch wire from Pin-4 to a white Latching Switch captures the first bit's physical state changes.
const unsigned int bit2_status_led = 5; // From Pin-5, the bit2_status_led wire leads to a blue LED displaying the second bit's status linked to medication events.
const unsigned int sense_bit2_hall_effect_sensor = 6; // The sense_bit2_hall_effect_sensor wire from Pin-6 to a blue Hall Effect Sensor detects the magnetic changes for the second bit.
const unsigned int latch_bit2_latching_switch = 6; // Pin-6 also connects to a blue Latching Switch through the latch_bit2_latching_switch wire to lock the second bit's state.
const unsigned int am_pm_status_led = 7; // A yellow LED connected by the am_pm_status_led wire from Pin-7 indicates the AM or PM medication status.
const unsigned int sense_am_pm_hall_effect_sensor = 8; // The sense_am_pm_hall_effect_sensor wire from Pin-8 connects to a yellow Hall Effect Sensor to detect AM/PM status changes.
const unsigned int latch_am_pm_latching_switch = 8; // Also from Pin-8, the latch_am_pm_latching_switch wire links to a yellow Latching Switch for AM/PM state capture.
const unsigned int wheel_status_led = 9; // Pin-9's wheel_status_led wire attaches to a red LED, which shows the wheel movement status, reflecting medication dispensing actions.
const unsigned int sense_wheel_hall_effect_sensor = 10; // Connecting Pin-10 to a red Hall Effect Sensor, the sense_wheel_hall_effect_sensor wire monitors wheel movements for medication timings.
const unsigned int latch_wheel_latching_switch = 10; // The latch_wheel_latching_switch wire from Pin-10 to a red Latching Switch secures the wheel's position post-movement.
const unsigned int status_status_led = 11; // Finally, the status_status_led wire leads from Pin-11 to an orange LED for general status indication of the system.

// *** Reminders constants **
const unsigned int initial_times_to_beep = 5; // The number of times that the sound should occur
const unsigned int initial_reminder_delay_seconds = 2; // How many seconds should be between the first reminder, and the second

// *** SpeedOfTime constants **
#ifdef DEBUG  //How many millisconds should a "minute" be
const unsigned int ms_per_minute = 8000;
#else
const unsigned int ms_per_minute = 60000;
#endif

#ifdef DEBUG  //How many "minutes" should be in a day
const unsigned int minutes_per_day = 4;
#else
const unsigned int minutes_per_day = 1440;
#endif

const unsigned int ms_between_beeps = 85; // Milliseconds that should be silent between beeps