#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer){

}
TEST_TEAR_DOWN(CircularBuffer){
    
}

TEST(CircularBuffer,CorecttSizeAffterCreate){
    uint8_t virtualBuffer[10];
    uint8_t size_actual;
    CircularBuffer_Create(virtualBuffer,sizeof(virtualBuffer)/sizeof(virtualBuffer[0]));
    size_actual=CircularBuffer_Size();
    TEST_ASSERT_EQUAL_UINT8(size_actual,10);  
}

TEST(CircularBuffer,EmnptyBufferAfterCreate){
    uint8_t virtualBuffer[10];
    uint8_t numberElements;
    CircularBuffer_Create(virtualBuffer,sizeof(virtualBuffer)/sizeof(virtualBuffer[0]));
    numberElements=CricularBuffer_NumberElements();
    TEST_ASSERT_EQUAL_UINT8(numberElements,0);
}

TEST(CircularBuffer, PutOneElement){
    uint8_t virtualBuffer[10];
    CircularBuffer_Create(virtualBuffer,sizeof(virtualBuffer)/sizeof(virtualBuffer[0]));
    CircularBuffer_Put(5);
    TEST_ASSERT_EQUAL_UINT8(virtualBuffer[0],5);
    TEST_ASSERT_EQUAL_UINT8(CricularBuffer_NumberElements(),1);

}

TEST(CircularBuffer,GetOneElement){
    uint8_t virtualBuffer[10];
    uint8_t Element;
    CircularBuffer_Create(virtualBuffer,sizeof(virtualBuffer)/sizeof(virtualBuffer[0]));
    CircularBuffer_Put(7);
    Element = CircularBuffer_Get();
    TEST_ASSERT_EQUAL_UINT8(virtualBuffer[0],0);
    TEST_ASSERT_EQUAL_UINT8(CricularBuffer_NumberElements(),0);

}