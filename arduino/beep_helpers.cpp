// beep_helpers.cpp
#include "Arduino.h"
#include "constants.cpp"

void beep(short beepType) {
  for (int i = 0; i < sizeof(beepFrequencies) / sizeof(beepFrequencies[0]); ++i) {
    if (beepType == i) {
      tone(speakerPin, beepFrequencies[i], beepDurationsMs[i]);
      delay(beepDurationsMs[i]); // Wait for the beep to finish
    }
  }
}

void emitBeepSequence(int beepId, int beepCount) {
  for (int i = 0; i < beepCount; ++i) {
    beep(beepId);
    delay(100); // Delay between beeps
  }
}
