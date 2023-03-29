#include "Led.h"

Led orange(LED_BUILTIN);

void setup() {
  orange.init();
}

void loop() {
  
  orange.on();
  delay(1000);
  orange.off();
  delay(1000);
}
