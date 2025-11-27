/**
* Copyright (c) 2023, AstroCeta, Inc. All rights reserved.
* \file ProtoclOfRingBuffer.h
* \brief Implementation of a ring buffer for efficient data handling.
* \date 2025-07-30
* \author AstroCeta, Inc.
**/
#include "ProtoclOfRingBuffer.h"


void ProtoclRingBuffInit(CBuff *buffer, uint8_t *pBuff, uint32_t size)
{
    buffer->pBuff = pBuff;
    buffer->Size = size;
    buffer->Head = 0;
    buffer->Tail = 0;
}

uint32_t ProtoclRBGetLength(const CBuff *buffer)
{
    return (buffer->Head >= buffer->Tail) ? (buffer->Head - buffer->Tail) : (buffer->Size + buffer->Head - buffer->Tail);
}


bool ProtoclOfRBuffPush(CBuff *buffer, const uint8_t *data, uint32_t len)
{
    uint32_t freeSpace = buffer->Size - ProtoclRBGetLength(buffer) - 1; 
    uint32_t Head,i;

    if (freeSpace < len)
    {
        return false; 
    }

    Head = buffer->Head;
    for (i = 0; i < len; i++)
    {
        buffer->pBuff[Head] = data[i];
        Head = (Head + 1) % buffer->Size;
    }
    buffer->Head = Head;

    return true; 
}

bool ProtoclRBuffPeek(CBuff *buffer, uint8_t *data, uint32_t len)
{
    uint32_t availableData = ProtoclRBGetLength(buffer);
    uint32_t Tail,i;

    if (availableData < len)
    {
        return false; 
    }
    
    Tail = buffer->Tail;
    for (i = 0; i < len; i++)
    {
        data[i] = buffer->pBuff[Tail];
		Tail = (Tail + 1) % buffer->Size;
    }
    
    return true; 
}

bool ProtoclRBuffPop(CBuff *buffer, uint8_t *data, uint32_t len)
{
    uint32_t availableData = ProtoclRBGetLength(buffer);
    uint32_t Tail,i;

    if (availableData < len)
    {
        return false; 
    }
    
    Tail = buffer->Tail;
    for (i = 0; i < len; i++)
    {
        data[i] = buffer->pBuff[Tail];
        Tail = (Tail + 1) % buffer->Size;
    }
    buffer->Tail = Tail;
    return true; 
}


void ProtoclRBuffClear(CBuff *buffer)
{
    buffer->Head = 0;
    buffer->Tail = 0;
}


bool ProtoclRBuffIsEmpty(const CBuff *buffer)
{
    return (buffer->Head == buffer->Tail);
}


bool ProtoclRBuffIsFull(const CBuff *buffer)
{
    return ((buffer->Head + 1) % buffer->Size) == buffer->Tail;
}


uint32_t ProtoclRBuffGetFreeSpace(const CBuff *buffer)
{
    return buffer->Size - ProtoclRBGetLength(buffer) - 1; 
}

/**************************End of file********************************/


