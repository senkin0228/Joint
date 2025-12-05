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
    TIM1->PSC = 30000;
    TIM1->ARR = 10000;
    TIM1->CCR1 = 2000;
    TIM1->CCR2 = 5000;
    TIM1->CCR3 = 8000;
	TIM1->CCR4 = 2000;
	HAL_TIM_Base_Start( &htim1);
    HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
}

void BspTIMGetOutput()
{
    if((GPIOA->IDR & GPIO_PIN_8) != 0){
        g_FloatTxData[4] = 1;
    } else{
        g_FloatTxData[4] = 0;
    }

    if((GPIOA->IDR & GPIO_PIN_9) != 0){
        g_FloatTxData[5] = 1;
    } else{
        g_FloatTxData[5] = 0;
    }

    if((GPIOA->IDR & GPIO_PIN_10) != 0){
        g_FloatTxData[6] = 1;
    } else{
        g_FloatTxData[6] = 0;
    }
        
}

/**************************End of file********************************/


