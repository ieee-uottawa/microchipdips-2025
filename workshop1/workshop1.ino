#include <stdint.h>
#include "gpio.h"

#define RED_PERIOD 500
#define GREEN_PERIOD 1000

// int led_r = 7;
// int led_g = 5;

Pin_t led_r = {7, &PORTD, &DDRD, &PIND};
Pin_t led_g = {5, &PORTD, &DDRD, &PIND};


typedef long long int time_t;

time_t lastBlink_red = 0;
time_t lastBlink_green = 0;


void setup() {
  // put your setup code here, to run once:

  // set pin 7 as an output;
  GPIO_PinMode(led_r, PIN_OUTPUT);
  GPIO_PinMode(led_g, PIN_OUTPUT);

  //DDRD = DDRD | 0b10000000;


}

void loop() {

  if(millis() - lastBlink_red > RED_PERIOD)
  {
    GPIO_Toggle(led_r);
    lastBlink_red = millis();
  }  

  if(millis() - lastBlink_green > GREEN_PERIOD)
  {
    GPIO_Toggle(led_g);
    lastBlink_green = millis();
  } 

}
