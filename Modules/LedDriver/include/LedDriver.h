#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stdint.h"

void LedDriver_Create(uint8_t * address);

void LedDriver_Destroy(void);

void LedDriver_TurnOn(uint8_t led_Numeber);

void LedDriver_TurnOff(uint8_t led_Number);

#endif