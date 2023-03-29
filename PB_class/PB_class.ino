#include "FourLeds.h"
#include "PB.h"


const int ledPins[] = {2, 3, 4, 5};

FourLeds leds(ledPins);
PB button(6);
int count;
void setup() {
  
button.init();

}

void loop() {
  
button.state();
count = button.getCount();
leds.displayCount(count);
}
