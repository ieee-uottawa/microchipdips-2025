#include <stdint.h>

#ifndef IEEE_GPIO
#define IEEE_GPIO

typedef struct
{
  int pin;
  volatile uint8_t * PORT;
  volatile uint8_t * DDR;
  volatile uint8_t * PIN;
} Pin_t;


typedef enum
{
  PIN_INPUT = 0,
  PIN_OUTPUT = 1
} PinMode_t;

typedef enum
{
  PIN_LOW = 0,
  PIN_HIGH = 1
} PinState_t;

void GPIO_PinMode(Pin_t pin, PinMode_t mode)
{
  *(pin.DDR) = (*(pin.DDR) & ~(0b1 << pin.pin)) | (mode << pin.pin);
}

void GPIO_Write(Pin_t pin, PinState_t state)
{
  *(pin.PORT) = (*(pin.PORT) & ~(0b1 << pin.pin)) | (state << pin.pin);
}

void GPIO_PortWrite(Pin_t pin, uint8_t states)
{
  *(pin.PORT) = states;
}

void GPIO_Toggle(Pin_t pin)
{
  *(pin.PORT) = *(pin.PORT) ^ (0b1 << pin.pin);
}

PinState_t GPIO_Read(Pin_t pin)
{
  return (PinState_t)((*(pin.PIN)>> pin.pin) & 0b1);
}

#endif