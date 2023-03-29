#ifndef FOURLEDS_H
#define FOURLEDS_H

#include <Arduino.h>

class FourLeds {

  private:
    int _ledPins[4];

  public:
    FourLeds(int ledPins[]);
    void displayCount(int count);
};

#endif
