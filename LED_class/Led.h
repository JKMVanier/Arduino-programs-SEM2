#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  private:
    int _pin;

  public:
    Led() {}
    Led(int pin);

    void init();
    void on();
    void off();
};

#endif
