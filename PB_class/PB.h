#ifndef FOURLEDS_H
#define FOURLEDS_H
#ifndef PB_H
#define PB_H

#include <Arduino.h>

class PB {

  private:

int _pin;
int _lastState = HIGH;
int _state;
unsigned long _lastDebounceTime = 0;
unsigned long _debounceDelay = 50;
int count = 0;



public:

PB(){}
PB(int pin);

void init();
void state();
int getCount();
  
};

class FourLeds{

  private:

int _ledPins[4];

 public:


FourLeds(int ledPins[]);
 void displayCount(int count);
  
 };
  

#endif
