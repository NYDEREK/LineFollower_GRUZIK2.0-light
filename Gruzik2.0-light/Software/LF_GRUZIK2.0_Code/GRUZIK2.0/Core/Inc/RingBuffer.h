/*
 * RingBuffer.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Szymon
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

#define RING_BUFFER_SIZE 64

// Success Status
typedef enum
{
  RB_OK       = 0,
  RB_ERROR    = 1
} RB_Status;

// Ring Buffer object
typedef struct
{
	uint16_t Head;
	uint16_t Tail;
	uint8_t Buffer[RING_BUFFER_SIZE];

} RingBuffer_t;

//Functions

//Write
RB_Status RB_Write(RingBuffer_t *Buf, uint8_t value);

//Read
RB_Status RB_Read(RingBuffer_t *Buf, uint8_t *value);

//FLush
void RB_Flush(RingBuffer_t *Buf);

#endif /* INC_RINGBUFFER_H_ */
