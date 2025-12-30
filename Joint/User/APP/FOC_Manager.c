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
#include "FOC.h"
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
	rtU.Motor_OnOff = 0;
    rtU.SpeedRef = 1200;
}


void FOC_Manager_Process(uint16_t TaskTick)
{
    static uint16_t adc_vbus,Vpoten = 0;
    static uint16_t SpeedRefTick = 0;
    //ADC_Process(TaskTick);
    BspTIMGetOutput();
    HAL_ADC_Start(&hadc2);
    Vpoten = HAL_ADC_GetValue(&hadc1);
    adc_vbus = HAL_ADC_GetValue(&hadc2);
	rtU.v_bus = ((float)adc_vbus)*3.3f/4096.0f*26.0f;
//    if(rtU.Motor_OnOff == 1) {
//        SpeedRefTick+=10;
//        if(SpeedRefTick == 5000) {
//            rtU.SpeedRef = 400;
//        } else if(SpeedRefTick == 20000) {
//            rtU.SpeedRef = 600;
//        }else if(SpeedRefTick == 30000) {
//            rtU.SpeedRef = 800;
//        }else if(SpeedRefTick >= 30000) {
//            SpeedRefTick = 30000;
//        }
//        
//    } else {
//        SpeedRefTick = 0;
//        rtU.SpeedRef = 400;
//    }
}


/**************************End of file********************************/


