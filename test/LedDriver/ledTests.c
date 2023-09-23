#include "unity_fixture.h"
#include "LedDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver){
}

TEST_TEAR_DOWN(LedDriver){
}

TEST(LedDriver,LedsOffAfterCreate){
	uint8_t virtualLeds = 0Xff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX8(0,virtualLeds);
}

TEST(LedDriver, TurnOnLedOne){
	uint8_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX8(1,virtualLeds);
}

TEST(LedDriver, TurnOffLedOne){
	uint8_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0,virtualLeds);
}


