#include "unity_fixture.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer){

}
TEST_TEAR_DOWN(CircularBuffer){
    
}
TEST(CircularBuffer,EmnptyBufferAfterCreate){
    TEST_FAIL_MESSAGE("FAIL!! circularbuffer");
}