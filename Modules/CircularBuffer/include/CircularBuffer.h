#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_
#include "stdint.h"

void CircularBuffer_Create(uint8_t size);

uint8_t CricularBuffer_NumberElements(void);

uint8_t CircularBuffer_Size(void);

#endif
