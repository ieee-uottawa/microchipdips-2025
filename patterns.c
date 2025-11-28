#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"

#define ON_PERIOD 500
#define OFF_PERIOD 500

Pin_t led_r = { 2, &PORTD, &DDRD, &PIND };
Pin_t led_y = { 3, &PORTD, &DDRD, &PIND };
Pin_t led_g = { 4, &PORTD, &DDRD, &PIND };

uint8_t sequence[] = {
  0b00000000,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00000000,
  0b00010000,
  0b00001000,
  0b00000100
}


int sequence_index = 0;
bool led_state = false;

typedef long long int time_t;

time_t lastToggle = 0;

void ieee_setup() {
  // set led pins as outputs
  GPIO_PinMode(led_r, PIN_OUTPUT);
  GPIO_PinMode(led_y, PIN_OUTPUT);
  GPIO_PinMode(led_g, PIN_OUTPUT);
}

void ieee_loop() {
   
  if(millis() - lastToggle > OFF_PERIOD && !led_state)
  {
    sequence_index = (sequence_index + 1) % (sizeof(sequence) / sizeof(uint8_t));
    GPIO_PortWrite(sequence[sequence_index]);
    lastToggle = millis();
  }

  if(millis() - lastToggle > ON_PERIOD && led_state)
  {
    GPIO_PortWrite(0b00000000);
    lastToggle = millis();
  }

}

int main() {
  // setup once
  ieee_setup();
  // loop forever
  for(;;)
  {
    ieee_loop();
  }
}
