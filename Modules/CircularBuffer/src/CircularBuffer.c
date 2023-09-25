#include "CircularBuffer.h"
#include <stdio.h>  
static uint8_t buffer_size;
static uint8_t number_elements;
uint8_t * p_buffer;
void CircularBuffer_Create(uint8_t *address ,uint8_t size){
    buffer_size=size;
    number_elements=0;
    p_buffer = address;
}

uint8_t CricularBuffer_NumberElements(){
    return number_elements;
}

uint8_t CircularBuffer_Size(void){
    return buffer_size;
}

void CircularBuffer_Put(uint8_t value){
    number_elements++;
    *p_buffer=value;
}

uint8_t CircularBuffer_Get(void){
    number_elements--;
    *p_buffer=0;
    return 0;
}