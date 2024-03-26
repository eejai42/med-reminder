#pragma once
/* Project Constant HEADERS
 ************  NOTE! This file is derived using Handlebars 
 ************  Source model json in /SSoT/ folder
 ************  ssotme json-hbars-transform -i /SSoT/source-data.json -i constants.hbars -o ../constants.cpp
 ************  ssotme json-hbars-transform -i /SSoT/source-data.json -i constantHeaders.hbars -o ../constants.h
*/



// *** Debouncing constants **
extern const unsigned long debounce_delay; // Debounce delay in milliseconds
extern const unsigned long wheel_turn_debounce_ms; // Debounce time for wheel turn detection
extern const unsigned long quick_turn_threshold_ms; // Threshold for quick turn detection

// *** Parts constants **
extern const unsigned int status_beeps_speaker; // The status_beeps_speaker wire connects Pin-2 to a speaker emitting auditory beeps for status alerts in an orange color.
extern const unsigned int bit1_status_led; // The bit1_status_led wire runs from Pin-3 to a white LED indicating the status of the first bit for medication timing.
extern const unsigned int sense_bit1_hall_effect_sensor; // Connecting Pin-4 to a white Hall Effect Sensor, the sense_bit1_hall_effect_sensor wire senses the first bit's magnetic field change.
extern const unsigned int latch_bit1_latching_switch; // The latch_bit1_latching_switch wire from Pin-4 to a white Latching Switch captures the first bit's physical state changes.
extern const unsigned int bit2_status_led; // From Pin-5, the bit2_status_led wire leads to a blue LED displaying the second bit's status linked to medication events.
extern const unsigned int sense_bit2_hall_effect_sensor; // The sense_bit2_hall_effect_sensor wire from Pin-6 to a blue Hall Effect Sensor detects the magnetic changes for the second bit.
extern const unsigned int latch_bit2_latching_switch; // Pin-6 also connects to a blue Latching Switch through the latch_bit2_latching_switch wire to lock the second bit's state.
extern const unsigned int am_pm_status_led; // A yellow LED connected by the am_pm_status_led wire from Pin-7 indicates the AM or PM medication status.
extern const unsigned int sense_am_pm_hall_effect_sensor; // The sense_am_pm_hall_effect_sensor wire from Pin-8 connects to a yellow Hall Effect Sensor to detect AM/PM status changes.
extern const unsigned int latch_am_pm_latching_switch; // Also from Pin-8, the latch_am_pm_latching_switch wire links to a yellow Latching Switch for AM/PM state capture.
extern const unsigned int wheel_status_led; // Pin-9's wheel_status_led wire attaches to a red LED, which shows the wheel movement status, reflecting medication dispensing actions.
extern const unsigned int sense_wheel_hall_effect_sensor; // Connecting Pin-10 to a red Hall Effect Sensor, the sense_wheel_hall_effect_sensor wire monitors wheel movements for medication timings.
extern const unsigned int latch_wheel_latching_switch; // The latch_wheel_latching_switch wire from Pin-10 to a red Latching Switch secures the wheel's position post-movement.
extern const unsigned int status_status_led; // Finally, the status_status_led wire leads from Pin-11 to an orange LED for general status indication of the system.

// *** Reminders constants **
extern const unsigned int initial_times_to_beep; // The number of times that the sound should occur
extern const unsigned int initial_reminder_delay_seconds; // How many seconds should be between the first reminder, and the second

// *** SpeedOfTime constants **
extern const unsigned int ms_per_minute; // How many millisconds should a "minute" be
extern const unsigned int minutes_per_day; // How many "minutes" should be in a day
extern const unsigned int ms_between_beeps; // Milliseconds that should be silent between beeps