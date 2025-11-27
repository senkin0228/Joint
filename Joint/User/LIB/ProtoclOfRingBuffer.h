/**
* Copyright (c) 2023, AstroCeta, Inc. All rights reserved.
* \file lib_ringbuffer.h
* \brief Implementation of a ring buffer for efficient data handling.
* \date 2025-07-30
* \author AstroCeta, Inc.
**/
#ifndef _PROTOCOL_RINGBUFFER_H_
#define _PROTOCOL_RINGBUFFER_H_

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif

typedef struct {
    uint16_t HandleLen;
    uint16_t DataLen;
    uint8_t  OverTime;
    uint8_t *pBuff;        
    uint32_t Size;         
    uint32_t Head;         
    uint32_t Tail;
} CBuff;

/**
* @brief Init the circular buffer.
* @param buffer: Pointer to the circular buffer structure.
* @param pBuff: Pointer to the buffer memory.
* @param size: Size of the buffer.
* @return None.
**/
void ProtoclRingBuffInit(CBuff *buffer, uint8_t *pBuff, uint32_t size);

/**
* @brief Get the current length of the circular buffer.
* @param buffer: Pointer to the circular buffer structure.
* @return The number of elements currently in the buffer.
**/
uint32_t ProtoclRBGetLength(const CBuff *buffer);

/**
* @brief Push data to the circular buffer.
* @param buffer: Pointer to the circular buffer structure.
* @param data: Pointer to the data to Push.
* @param len: Length of the data to Push.
* @return true if the data was written successfully, false if there is not enough space.
**/

bool ProtoclOfRBuffPush(CBuff *buffer, const uint8_t *data, uint32_t len);

/**
* @brief Pop data from the circular buffer, removing it from the buffer.
* @param buffer: Pointer to the circular buffer structure.
* @param data: Pointer to the buffer where data will be popped into.
* @param len: Length of the data to pop.
* @return true if the data was popped successfully, false if there is not enough data.
**/
bool ProtoclRBuffPop(CBuff *buffer, uint8_t *data, uint32_t len);

/**
* @brief Read data from the circular buffer without removing it.
* @param buffer: Pointer to the circular buffer structure.
* @param data: Pointer to the buffer where data will be read into.
* @param len: Length of the data to read.
* @return true if the data was read successfully, false if there is not enough data.
**/
bool ProtoclRBuffPeek(CBuff *buffer, uint8_t *data, uint32_t len);

/**
* @brief Clear the circular buffer.
* @param buffer: Pointer to the circular buffer structure.
* @return None. 
**/

void ProtoclRBuffClear(CBuff *buffer);
/**
* @brief Check if the circular buffer is empty.
* @param buffer: Pointer to the circular buffer structure.
* @return true if the buffer is empty, false otherwise. 
**/

bool ProtoclRBuffIsEmpty(const CBuff *buffer);
/**
* @brief Check if the circular buffer is full.
* @param buffer: Pointer to the circular buffer structure.
* @return true if the buffer is full, false otherwise.
**/
bool ProtoclRBuffIsFull(const CBuff *buffer);

/**
* @brief Get the amount of free space in the circular buffer.
* @param buffer: Pointer to the circular buffer structure.
* @return The number of free bytes available in the buffer.
**/
uint32_t ProtoclRBuffGetFreeSpace(const CBuff *buffer);

#ifdef __cplusplus
}
#endif
#endif  // LIB_RINGBUFFER_H
/**************************End of file********************************/

