/*
 * RingBuffer.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Szymon
 */
#include "main.h"
#include "RingBuffer.h"

RB_Status RB_Write(RingBuffer_t *Buf, uint8_t value)
{
	uint8_t HeadTmp = (Buf->Head + 1) % RING_BUFFER_SIZE;

	if(HeadTmp == Buf->Tail)
	{
		return RB_ERROR;
	}

	Buf->Buffer[Buf->Head] = value;

	Buf->Head = HeadTmp;

	return RB_OK;
}

RB_Status RB_Read(RingBuffer_t *Buf, uint8_t *value)
{
	if(Buf->Head == Buf->Tail)
	{
		return RB_ERROR;
	}

	*value = Buf->Buffer[Buf->Tail];

	Buf->Tail = (Buf->Tail + 1) % RING_BUFFER_SIZE;

	return RB_OK;
}
void RB_Flush(RingBuffer_t *Buf)
{
	Buf->Head = 0;
	Buf->Tail = 0;

}
