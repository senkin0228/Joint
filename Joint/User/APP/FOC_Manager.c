/***********************************************************************************
* @file     : FOC_Manager.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "FOC_Manager.h"
#include "VF.h"
#include "App_ADC.h"
#include "BspTIM.h"
#include "gpio.h"
#include "log.h"
#include "adc.h"


extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern ExtY rtY;
extern ExtU rtU;

void FOC_Manager_Init(void)
{
    rtU.ud = 0;
	rtU.uq = 12;
	rtU.Freq = 4;
}


void FOC_Manager_Process(uint16_t TaskTick)
{
    static uint16_t adc_vbus = 0;
    //ADC_Process(TaskTick);
    BspTIMGetOutput();
    HAL_ADC_Start(&hadc2);
    adc_vbus = HAL_ADC_GetValue(&hadc2);
	rtU.v_bus = ((float)adc_vbus)*3.3f/4096.0f*26.0f;
}


/**************************End of file********************************/


