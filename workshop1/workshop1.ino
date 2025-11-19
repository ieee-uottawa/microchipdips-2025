#include <stdint.h>
#include "gpio.h"

#define RED_PERIOD 200
#define GREEN_PERIOD 1000

int led_r = 7;
int led_g = 5;


typedef long long int time_t;

time_t lastBlink_red = 0;
time_t lastBlink_green = 0;


void setup() {
  // put your setup code here, to run once:

  // set pin 7 as an output;
  GPIO_PinMode(&DDRD, led_r, PIN_OUTPUT);
  GPIO_PinMode(&DDRD, led_g, PIN_OUTPUT);

  //DDRD = DDRD | 0b10000000;

}

void loop() {

  if(millis() - lastBlink_red > RED_PERIOD)
  {
    GPIO_Toggle(&PORTD, led_r);
    lastBlink_red = millis();
  }  

  if(millis() - lastBlink_green > GREEN_PERIOD)
  {
    GPIO_Toggle(&PORTD, led_g);
    lastBlink_green = millis();
  } 

}
