/**
* Copyright (c) 2023, AstroCeta, Inc. All rights reserved.
* \file BspCommUsart.h
* \brief Implementation of a ring buffer for efficient data handling.
* \date 2025-07-30
* \author AstroCeta, Inc.
**/
#ifndef BSP_COMM_USART_H
#define BSP_COMM_USART_H

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif


#define DMA_RX_BUFFER_SIZE 256

typedef enum {
    UsartInstance3,
    UsartInstanceMax
} UsartInstance_t;

/* USART Status Enumeration */
typedef enum {
    UsartStatusOk = 0,
    UsartStatusError,
    UsartStatusBusy,
    UsartStatusTimeout
} UsartStatus_t;

void BspUsartInit(void);
void HAL_UART_DMAIdleCallback(void);
/* Transmission Functions */
UsartStatus_t BspUsartSendData(UsartInstance_t instance, uint8_t* data, uint16_t length);
UsartStatus_t BspUsartSendString(UsartInstance_t instance, const char* string);
bool BspUsartIsTxBusy(UsartInstance_t instance);
/* Reception Functions */
uint16_t BspUsartGetRxDataCount(UsartInstance_t instance);
UsartStatus_t BspUsartGetRxData(UsartInstance_t instance, uint8_t* buffer, uint16_t maxLength);
void BspUsartClearRxBuffer(UsartInstance_t instance);
void BspUartSendJustFloatData(UsartInstance_t instance, float *data, uint16_t length);
void SEGGER_RTT_printf(const char * sFormat, ...);
#ifdef __cplusplus
}
#endif
#endif  // BSP_COMM_USART_H
/**************************End of file********************************/

