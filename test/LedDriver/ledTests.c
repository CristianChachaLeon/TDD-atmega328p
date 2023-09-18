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


