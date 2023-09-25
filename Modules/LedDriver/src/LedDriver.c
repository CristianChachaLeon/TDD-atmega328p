#include "LedDriver.h"
static uint8_t * ledsAddress;
void LedDriver_Create(uint8_t * address){
    ledsAddress= address;
    *ledsAddress = 0;
}

void LedDriver_Destroy(){

}

void LedDriver_TurnOn(uint8_t led_Numeber)
{
    *ledsAddress=1;
}

void LedDriver_TurnOff(uint8_t led_Number)
{
    *ledsAddress=0;
}
