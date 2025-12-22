/***********************************************************************************
* @file     : BspExit.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "BspExit.h"
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "FOC.h"
extern ExtU rtU;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
    static uint8_t Motor_state = 0;
    UNUSED(GPIO_Pin);
	if(BTN1_Pin == GPIO_Pin)
	{
		Motor_state = ~Motor_state;
		if(0 == Motor_state)
		{
            rtU.Motor_OnOff = 0;
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
		}
		else
		{
            rtU.Motor_OnOff = 1;
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
		}
	}
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}




/**************************End of file********************************/


