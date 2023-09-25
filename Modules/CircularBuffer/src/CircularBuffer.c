#include "CircularBuffer.h"
static uint8_t buffer_size;
void CircularBuffer_Create(uint8_t size){
    buffer_size=size;
}

uint8_t CricularBuffer_NumberElements(){
    return 0;
}

uint8_t CircularBuffer_Size(void){
    return buffer_size;
}