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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
    UNUSED(GPIO_Pin);
	if(BTN1_Pin == GPIO_Pin)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	}
	if(BTN2_Pin == GPIO_Pin)
	{
		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
	}
	if(BTN3_Pin == GPIO_Pin)
	{
		HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,GPIO_PIN_RESET);
	}
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}




/**************************End of file********************************/


