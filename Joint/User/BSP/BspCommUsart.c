/**
* Copyright (c) 2023, AstroCeta, Inc. All rights reserved.
* \file BspCommUsart.h
* \brief Implementation of a ring buffer for efficient data handling.
* \date 2025-07-30
* \author AstroCeta, Inc.
**/
#include "BspCommUsart.h"
#include "ProtoclOfRingBuffer.h"
#include "usart.h"

extern UART_HandleTypeDef huart3;


static UART_HandleTypeDef *UsartControlTable[UsartInstanceMax];
static uint8_t Bsp_DMARxBuffer[UsartInstanceMax][DMA_RX_BUFFER_SIZE];
static uint8_t Bsp_RingRxBuffer[UsartInstanceMax][DMA_RX_BUFFER_SIZE];
static CBuff Bsp_DMA_RB[UsartInstanceMax];

void BspUsartInit(void)
{
    UsartControlTable[UsartInstance3] = &huart3;

    for(int i = 0; i < UsartInstanceMax; i++) {
        HAL_UART_MspInit(UsartControlTable[i]);
        ProtoclRingBuffInit(&Bsp_DMA_RB[i], Bsp_RingRxBuffer[i], DMA_RX_BUFFER_SIZE);
        __HAL_UART_ENABLE_IT(UsartControlTable[i], UART_IT_IDLE);
        HAL_UART_Receive_DMA(UsartControlTable[i], Bsp_DMARxBuffer[i], sizeof(Bsp_DMARxBuffer[i]));       
    }
}

void HAL_UART_DMAIdleCallback()
{
    if( __HAL_UART_GET_FLAG(UsartControlTable[UsartInstance3], UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(UsartControlTable[UsartInstance3]);       
        // Handle USART3 reception complete
        HAL_UART_DMAStop(UsartControlTable[UsartInstance3]);          // 停止DMA（防止数据被覆盖）
        uint16_t rxLen = DMA_RX_BUFFER_SIZE - __HAL_DMA_GET_COUNTER(UsartControlTable[UsartInstance3]->hdmarx);
        ProtoclOfRBuffPush(&Bsp_DMA_RB[UsartInstance3], Bsp_DMARxBuffer[UsartInstance3], rxLen);
        HAL_UART_Receive_DMA(UsartControlTable[UsartInstance3], Bsp_DMARxBuffer[UsartInstance3], DMA_RX_BUFFER_SIZE); // 重启接收
        return;
    }
}

UsartStatus_t BspUsartSendData(UsartInstance_t instance, uint8_t* data, uint16_t length)
{
    if(HAL_UART_Transmit_DMA(UsartControlTable[instance], data, length) != HAL_OK) {
        return UsartStatusError;
    }
    return UsartStatusOk;
};

bool BspUsartIsTxBusy(UsartInstance_t instance){
    return (UsartControlTable[instance]->gState == HAL_UART_STATE_BUSY_TX);
}

/* Reception Functions */
uint16_t BspUsartGetRxDataCount(UsartInstance_t instance)
{
    return ProtoclRBGetLength(&Bsp_DMA_RB[instance]);
}

UsartStatus_t BspUsartGetRxData(UsartInstance_t instance, uint8_t* buffer, uint16_t maxLength)
{
    if (buffer == NULL || maxLength == 0) {
        return UsartStatusError;
    }

    uint16_t dataLength = ProtoclRBGetLength(&Bsp_DMA_RB[instance]);
    if (dataLength == 0) {
        return UsartStatusError;
    }

    if (dataLength > maxLength) {
        dataLength = maxLength;
    }

    ProtoclRBuffPop(&Bsp_DMA_RB[instance], buffer, dataLength);
    return UsartStatusOk;
}

void BspUsartClearRxBuffer(UsartInstance_t instance)
{
    ProtoclRBuffClear(&Bsp_DMA_RB[instance]);
}
void SEGGER_RTT_printf(const char * sFormat, ...){};


void BspUartSendJustFloatData(UsartInstance_t instance, float *data, uint16_t length)
{
    static uint8_t txBuffer[64];
    static uint8_t index = 0;
    for(uint16_t i = 0; i < length; i++) {
        memcpy(&txBuffer[i * 4], (uint8_t *)&data[i], sizeof(float));
        index += 4;
    }
    txBuffer[index++] = 0x00;
    txBuffer[index++] = 0x00;
    txBuffer[index++] = 0x80;
    txBuffer[index++] = 0x7f;
    if(BspUsartSendData(instance, txBuffer, index) == UsartStatusError) {
        HAL_Delay(1);
        BspUsartSendData(instance, txBuffer, index);
    }
    index = 0;
}

/**************************End of file********************************/


