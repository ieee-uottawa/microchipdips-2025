#include <stdint.h>

#ifndef IEEE_GPIO
#define IEEE_GPIO


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

void GPIO_PinMode(volatile uint8_t *DDR, uint8_t pin, PinMode_t mode)
{
  *DDR = ( *DDR & ~(0b1 << pin)) | (mode << pin);
}

void GPIO_Write(volatile uint8_t *PORT, uint8_t pin, PinState_t state)
{
  *PORT = (*PORT & ~(0b1 << pin)) | (state << pin);
}

void GPIO_Toggle(volatile uint8_t *PORT, uint8_t pin)
{
  *PORT = *PORT ^ (0b1 << pin);
}

PinState_t GPIO_Read(volatile uint8_t *PIN, uint8_t pin)
{
  return (PinState_t)((*PIN >> pin) & 0b1);
}

#endif