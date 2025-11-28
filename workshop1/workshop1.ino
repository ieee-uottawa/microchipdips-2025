#include <stdint.h>
#include "gpio.h"

#define RED_PERIOD 500
#define GREEN_PERIOD 1000

Pin_t led_r = {3, &PORTD, &DDRD, &PIND};
Pin_t led_g = {2, &PORTD, &DDRD, &PIND};


typedef long long int time_t;

time_t lastBlink_red = 0;
time_t lastBlink_green = 0;

void setup() {
  // set led pins as outputs
  GPIO_PinMode(led_r, PIN_OUTPUT);
  GPIO_PinMode(led_g, PIN_OUTPUT);
}

void loop() {
   if (millis() - lastBlink_red > RED_PERIOD) {
    GPIO_Toggle(led_r);
    lastBlink_red = millis();
  }

  if (millis() - lastBlink_green > GREEN_PERIOD) {
    GPIO_Toggle(led_g);
    lastBlink_green = millis();
  }
}

 