#ifndef ALARM_HELPERS_H
#define ALARM_HELPERS_H


struct DayTime {
  int dow; // Day of the week (1 = Monday, ... 7 = Sunday)
  bool isAM; // Time of day (1 = morning, 0 = evening)
  int system_day;
  int system_minutes;
  int timer2_minutes;
};


// Function prototypes
void setupAlarms();
void checkAlarms();
void triggerTimer();
int getTimer2Minutes();
int days_into_cycle();
void startReminding();   
void stopReminding();
void simulateSetupTime();   
unsigned long minutes_since_day_started();

DayTime getDayAndTime();
void printDowTod();
void printSystemTime();
bool  getIsAM();
void setIsAM(bool isAm);
String minutesToAMPMString(int minutes);


void printSetTimerMsg(String msg, int timer);
void beep(int duration);
void emitBeepSequence(int beepId, int beepCount);

#endif