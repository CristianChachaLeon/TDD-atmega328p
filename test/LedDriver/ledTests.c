#include "unity_fixture.h"
#include "LedDriver.h"

static uint8_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver){
	LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver){
}

TEST(LedDriver,LedsOffAfterCreate){
	uint8_t virtualLeds = 0Xff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX8(0,virtualLeds);
}

TEST(LedDriver, TurnOnLedOne){
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX8(1,virtualLeds);
}

TEST(LedDriver, TurnOffLedOne){
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX8(0,virtualLeds);
}


