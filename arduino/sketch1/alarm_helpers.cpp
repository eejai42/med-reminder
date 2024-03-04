#include "Arduino.h"
#include "constants.h"
#include "wheel_helpers.h"
#include "alarm_helpers.h"

// Timer states
unsigned long currentMinutes = 0;
int initialDay =0;
unsigned long timer = -1;  // Minute mark for the second timer
bool timerSet = false;
bool reminding = false;
int remindedTimes = 0;

int getTimer2Minutes() {
  return timer;
}

int days_into_cycle() {

  int dayNumber = floor(millis() / msPerMinute / minutesPerDay);
  int currentDay = initialDay + (dayNumber % 14) + 1;

  return currentDay;
}

void setupAlarms() {
  pinMode(speakerPin, OUTPUT);
  DayTime dt = getDayAndTime();
  initialDay = dt.dow;
}

void checkAlarms() {
  unsigned long tempMinutes = minutes_since_day_started();
  if (tempMinutes != currentMinutes) {
    currentMinutes = tempMinutes;
    if ((millis() % 1000) < 10) {
      Serial.println();
      Serial.print(" ----- TOP OF THE MINUTE: ");
      Serial.print(currentMinutes);
      printDowTod();
    }

    if ((currentMinutes == 0) || (currentMinutes == getTimer2Minutes())) {
      startReminding();
    }
  }
}

void startReminding() {
  Serial.println();
  Serial.println();
  Serial.println("          ************   ALARM - ALARM - ALARM!!!! *********** ");
  if (getIsAM()) {
    Serial.println("          ************          MORNING          *********** ");
  } else {
    Serial.println("          ************          evening          *********** ");
  }
  Serial.println();
  Serial.println();
  printSystemTime();
  emitBeepSequence(100, 15);
}


void stopReminding() {
  if (reminding) {
    Serial.println("Pills taken!!!! Nice work!");
    emitBeepSequence(1000, 3);
  }
}

void triggerTimer() {
  unsigned long currentMinutes = minutes_since_day_started();
  if (millis() < 9000) {
    Serial.println("Timer 1 set for minute: 0");
    printDowTod();
  } else if (!timerSet) {
    timer = max(1, currentMinutes);
    timerSet = true;
    Serial.print("Timer 2 set for minutes: ");
    Serial.println(timer);
    printDowTod();
  } else {
    stopReminding();
  }
}

void simulateSetupTime() {
  delay(2500);
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print("Configuring med-alarm now");
  for (int i = 0; i < 3; i++) {
    delay(750);
    Serial.print(".");
  }
  Serial.println();
  Serial.println();
  Serial.println("Done.");
  Serial.println();
  Serial.println();
}

unsigned long minutes_since_day_started() {
  return (millis() / msPerMinute) % minutesPerDay;  // Convert milliseconds to minutes
}

void checkTimers() {
  if (timerSet) {
    unsigned long currentMinutes = minutes_since_day_started();

    if (currentMinutes == 0) {
      Serial.println("Timer reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }

    if (currentMinutes == timer) {
      Serial.println("Timer2 reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }
  }
}

void beep(int duration = 1000) {
  digitalWrite(speakerPin, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(duration);                 // Wait for a second (1000 milliseconds)
  digitalWrite(speakerPin, LOW);   // Turn the LED off by making the voltage LOW
}

void emitBeepSequence(int duration, int beepCount) {
  for (int i = 0; i < beepCount; ++i) {
    beep(duration);
    delay(duration);  // Delay between beeps
  }
}
