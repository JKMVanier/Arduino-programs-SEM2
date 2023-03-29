
#include "PB.h"
#include <Arduino.h>
#include "fourLeds.h"

PB::PB(int pin) {
  _pin = pin;
}

void PB::init(){

  
  digitalWrite(_pin, INPUT_PULLUP);
  Serial.begin(9600);

}


void PB::state(){


int val = digitalRead(_pin);

if (val != _lastState){
  _lastDebounceTime = millis();
}

if ((millis() - _lastDebounceTime) > _debounceDelay){
  if (val != _state){
     _state = val;

  

     if (_state == LOW){

        Serial.print("state:");
       Serial.print("pressed");
       
       
       Serial.print("\t");
     
       count++;
       Serial.print("presses:");
       Serial.println(count);
  }

  
  
}  
}

_lastState = val;

}


int PB::getCount() {
  return count;
}


void FourLeds :: displayCount(int count){

  digitalWrite(_ledPins[count], HIGH);

 }
///////////////////////////////////////////////////////////////

 
