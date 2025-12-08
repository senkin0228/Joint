/***********************************************************************************
* @file     : BspTIM.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "BspTIM.h"
#include "tim.h"

extern TIM_HandleTypeDef htim1;
extern float g_FloatTxData[12];

void BspTIM_Init(void)
{
    TIM1->ARR = 8000-1;
	TIM1->CCR4 = 8000-2;
	HAL_TIM_Base_Start( &htim1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
}

void BspTIMGetOutput()
{
    // if((GPIOA->IDR & GPIO_PIN_8) != 0){
    //     g_FloatTxData[4] = 1;
    // } else{
    //     g_FloatTxData[4] = 0;
    // }

    // if((GPIOA->IDR & GPIO_PIN_9) != 0){
    //     g_FloatTxData[5] = 1;
    // } else{
    //     g_FloatTxData[5] = 0;
    // }

    // if((GPIOA->IDR & GPIO_PIN_10) != 0){
    //     g_FloatTxData[6] = 1;
    // } else{
    //     g_FloatTxData[6] = 0;
    // }
        
}

/**************************End of file********************************/


