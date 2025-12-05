/***********************************************************************************
* @file     : App_ADC.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "App_ADC.h"
#include "BspCommUsart.h"
#include "BspADC.h"
#include "adc.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern float g_FloatTxData[12];

void ADC_Process(uint32_t tick)
{
    if(tick % 20 != 0)
        return;
   
    HAL_ADC_Start(&hadc1);
	HAL_ADC_Start(&hadc2);
    g_FloatTxData[3] = HAL_ADC_GetValue(&hadc1)*3.3f/4096.0f;  
    BspUartSendJustFloatData(UsartInstance3, g_FloatTxData, 4);
}


/**************************End of file********************************/


