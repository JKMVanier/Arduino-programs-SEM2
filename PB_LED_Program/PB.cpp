#include "PB.h"

PB::PB(int pin) {
  _pin = pin;
}

void PB::init() {
  pinMode(_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void PB::state() {
  int val = digitalRead(_pin);

  if (val != _lastState) {
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    if (val != _state) {
      _state = val;

      if (_state == LOW) {
        count++;
      }
    }
  }

  _lastState = val;
}

int PB::getCount() {
  if (count > 4) {
    count = 0;
  }
  return count;
}
