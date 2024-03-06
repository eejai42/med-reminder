#include "Arduino.h"
#include "constants.h"
#include "wheel_helpers.h"
#include "alarm_helpers.h"

// Timer states
unsigned long currentMinutes = 0;
bool is_am = false;
int initialDay = 0;
bool timer1IsAM = true;
int timer1OffsetMS = -1;
int timer1OffsetMinutes = -1;
unsigned long timer1 = -1;  // Minute mark for the second timer
unsigned long timer2 = -1;  // Minute mark for the second timer
bool reminding = false;
int beepsBeeped = 0;
double timesToBeep = initial_times_to_beep;
double secondsBetweenReminders = initial_reminder_delay_seconds;
unsigned long remindersSnoozedAtMS = 0;
unsigned long timer2SetAt = 0;

unsigned long mymillis() {
  // if (timer1OffsetMS > 0) {
  //   Serial.println(" ADDING:  " + String(timer1OffsetMS) + " to mymillis()....");
  // }
  return millis() + timer1OffsetMS;
}

int getTimer2Minutes() {
  return timer2;
}

int days_into_cycle() {

  int dayNumber = (int)floor(mymillis() / msPerMinute / minutesPerDay) % 7;
  int currentDay = (initialDay + dayNumber) % 7;

  return currentDay;
}

DayTime getDayAndTime(bool isWheel1, int sliceIndex) {

  bool isWheel2 = !isWheel1;
  int localSlice = sliceIndex;

  DayTime result;
  result.isAM = is_am;
  result.dow = getIndex() % 7;
  result.system_day = days_into_cycle();
  result.system_minutes = minutes_since_day_started();
  result.timer2_minutes = getTimer2Minutes();
  return result;
}

bool getIsAM() {
  return is_am;
}

void setupAlarms() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  DayTime dt = getDayAndTime();
}

void startReminding() {
  if ((timer2SetAt > 0) && (timer2SetAt + 3000 > mymillis())) {
    // Serial.println("NOT STARTING REMINDER - TOO SOON AFTER REMINDER SET");
    // Serial.println(timer2SetAt);
    // Serial.println(mymillis());

    return;
  }

  reminding = true;
  beepsBeeped = 0;
  remindersSnoozedAtMS = 0;

  Serial.println();
  Serial.println();
  Serial.println("          ************   ALARM - ALARM - ALARM!!!! *********** ");
  if (getIsAM()) {
    Serial.print("          ************        ^ MORNING ^        *********** ");
  } else {
    Serial.print("          ************        V evening V        *********** ");
  }
  Serial.println(String(is_am ? "PILLBOX: DAY" : "PILLBOX: NIGHT") + " TIMERS: " + minutesToAMPMString(timer1) + " vs. " + minutesToAMPMString(timer1));
  Serial.println();
  Serial.println();
  printSystemTime();
}


void stopReminding() {
  if (reminding) {

    reminding = false;
    remindersSnoozedAtMS = 0;
    Serial.println();
    Serial.println("            *******************************");
    Serial.println("            ** Pills taken!!!! Nice work **!");
    Serial.println("            *******************************");
    Serial.println();
  }
}

void snooze() {
  // Serial.print("                                    Snoozing for seconds: ");
  // Serial.println(secondsBetweenReminders);
  remindersSnoozedAtMS = mymillis();
}

bool isSnoozed() {
  if (remindersSnoozedAtMS > 0) {
    int secondsSinceSnoozed = (mymillis() - remindersSnoozedAtMS) / 1000;
    if (secondsSinceSnoozed > secondsBetweenReminders) {
      //Serial.println("DONE beeping");
      beepsBeeped = 0;
      remindersSnoozedAtMS = 0;
    }
  }
  return remindersSnoozedAtMS > 0;
}

bool beepCountExceeded() {
  bool countExceeded = beepsBeeped > timesToBeep;
  return countExceeded;
}

void emitAlarmBeep() {
  //Serial.println("beeping");
  beep(msBetweenBeeps);
  beepsBeeped++;
}

void emitBeepsOrSnooze() {
  if (!isSnoozed()) {
    if (beepCountExceeded()) {
      snooze();
    } else {
      emitAlarmBeep();
    }
  }
}


void checkAlarmBeeping() {
  if (reminding) emitBeepsOrSnooze();
}

void checkAlarms() {
    if (timer1OffsetMS == -1) {
      //timer1IsAM = getIsAM();
      timer1OffsetMinutes = 0; //timer1IsAM ? 0 : minutesPerDay / 2;
      timer1OffsetMS = 0; // timer1IsAM ? 0 : timer1OffsetMinutes * msPerMinute;
      if (timer1OffsetMS > 0) {
        Serial.println("INCLUDING OFFSETS: ADDING " + String(timer1OffsetMinutes));
      }
    }

  unsigned long tempMinutes = minutes_since_day_started();
  if (tempMinutes != currentMinutes) {
    currentMinutes = tempMinutes;
    if ((mymillis() % 1000) < 10) {
      Serial.println();
      printSystemTime();
      printDowTod();
      Serial.println();
    }

    if ((currentMinutes == timer1) || (currentMinutes == timer2)) {
      startReminding();
    }
  } else {
    checkAlarmBeeping();
  }
}

unsigned long minutes_since_day_started() {
  return (mymillis() / msPerMinute) % minutesPerDay;  // Convert milliseconds to minutes
}

void checkTimers() {
  if (timer2 != -1) {
    unsigned long currentMinutes = minutes_since_day_started();

    if (currentMinutes == timer1) {
      Serial.println("Timer reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }

    if (currentMinutes == timer2) {
      Serial.println("Timer2 reached: time1 reached");
      // Ensure message is not repeated by unsetting or adjusting the condition
    }
  }
}

void beep(int duration = 1000) {
  tone(speakerPin, 440, msBetweenBeeps * 2);
  digitalWrite(ledPin, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(msBetweenBeeps);       // Wait for a second (1000 milliseconds)
  digitalWrite(ledPin, LOW);   // Turn the LED off by making the voltage LOW
  delay(msBetweenBeeps);       // Wait for a second (1000 milliseconds)
}

void printSetTimerMsg(String msg, int timer) {
  Serial.println();
  Serial.println("            *******************************");
  Serial.print("            ** ");
  Serial.print(msg);
  Serial.println(minutesToAMPMString(timer));
  Serial.println("            *******************************");
}

void triggerTimer() {
  unsigned long currentMinutes = minutes_since_day_started();
  DayTime dt = getDayAndTime();
  String finalSliceTOD = (dt.isAM && timer1IsAM) ? "Evening " : "Morning ";
  //Serial.println("_______ TRIGGER DETECTED __________");
  if (mymillis() > 10000) {
    if ((timer1 == -1)) {
      timer1 = currentMinutes;

      timer2SetAt = mymillis();
      printSetTimerMsg(finalSliceTOD + " Reminder Set For 00:", timer1);
    } else if (timer2 == -1) {

      timer2 = (timer1 != currentMinutes) ? currentMinutes : max(timer1 + 1, currentMinutes);
      timer2SetAt = mymillis();
      printSetTimerMsg(finalSliceTOD + " Reminder set for 00:", timer2);
      printDowTod();
    } else {
      stopReminding();
    }
  } else {
    clearMovement();    
    initialDay = getIndex();
    Serial.println();
    Serial.println("      Done setting up Med Reminder v0.1");
    Serial.println();
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
}



void emitBeepSequence(int duration, int beepCount) {
  for (int i = 0; i < beepCount; ++i) {
    beep(duration);
    delay(duration);  // Delay between beeps
  }
}


DayTime getDayAndTime() {
  return getDayAndTime(getWheelNumber() == 1, getIndex());
}

void printDowTod() {
  DayTime dt = getDayAndTime();
  Serial.print("PILLBOX:      ");
  if (dt.dow) Serial.print("0");
  Serial.print(dt.dow);
  Serial.print(dt.isAM ? " Morning" : " Evening");
  Serial.println();
}

String getTOD(int minutes) {
  minutes = minutes % minutesPerDay;
  bool inFirstHalfOfDay = minutes < (minutesPerDay / 2);
  String tod = inFirstHalfOfDay ? "am" : "pm";
  // if (inFirstHalfOfDay) {
  //   tod = timer1IsAM ? "am" : "pm";
  // } else {
  //   tod = timer1IsAM ? "pm" : "am";
  // }
  return tod;
}

String minutesToAMPMString(int minutes) {
  String results = "";
  minutes++;
  minutes = (minutes + timer1OffsetMinutes) % minutesPerDay;
  String tod = getTOD(minutes);
  if (tod == "pm") minutes = minutes% (minutesPerDay); // / 2);
  if (minutes < 10) results = "0";
  results = results + String(minutes) + tod;
  // Serial.println();
  // Serial.println("                                                                                                              MINUTES TO AM PM STRING: " + results + " <= " + String(minutes));
  // Serial.println();

  return results;
}

void printSystemTime() {
  DayTime dt = getDayAndTime();
  Serial.print("SYSTEM DT:    ");
  if (dt.system_day < 10) Serial.print("0");
  Serial.print(dt.system_day);
  Serial.print(":00:");
  // Serial.print(":00:");
  // Serial.print(mymillis() % msPerMinute);
  Serial.print(minutesToAMPMString(dt.system_minutes));

  if (reminding) Serial.print("                                ---- REMINDING TAKE PILLS YO!!!!    -");
  Serial.print("    timer1 min:" + String(timer1) + " timer2 min: " + String(timer2));
  // if (dt.timer2_minutes < 10) "0";
  // Serial.print(dt.timer2_minutes);
  Serial.println();
}




void setIsAM(bool isAM) {
  is_am = isAM;
}