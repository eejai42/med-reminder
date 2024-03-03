#ifndef ALARM_HELPERS_H
#define ALARM_HELPERS_H

// Function prototypes
void setupAlarms();
void checkAlarms();
void triggerTimer();
int getTimer2Minutes();
int days_into_cycle();
unsigned long minutes_since_day_started();



void beep(short beepType);
void emitBeepSequence(int beepId, int beepCount);

#endif