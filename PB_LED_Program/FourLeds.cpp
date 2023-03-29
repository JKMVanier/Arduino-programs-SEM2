#include "FourLeds.h"

FourLeds::FourLeds(int ledPins[]) {
  for (int i = 0; i < 4; i++) {
    _ledPins[i] = ledPins[i];
    pinMode(_ledPins[i], OUTPUT);
    digitalWrite(_ledPins[i], LOW);
  }
}

void FourLeds::displayCount(int count) {
  if (count > 4) {
    count = 0;
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(_ledPins[i], i < count);
  }
}
