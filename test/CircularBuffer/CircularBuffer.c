#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer){

}
TEST_TEAR_DOWN(CircularBuffer){
    
}

TEST(CircularBuffer,CorecttSizeAffterCreate){
    uint8_t size = 10;
    uint8_t size_actual;
    CircularBuffer_Create(size);
    size_actual=CircularBuffer_Size();
    TEST_ASSERT_EQUAL_UINT8(size_actual,size);
    
}
TEST(CircularBuffer,EmnptyBufferAfterCreate){
    uint8_t numberElements;
    CircularBuffer_Create(10);
    numberElements=CricularBuffer_NumberElements();
    TEST_ASSERT_EQUAL_UINT8(numberElements,0);
}