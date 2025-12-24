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
#include "Drv_AS5600.h"

extern TIM_HandleTypeDef htim1;
extern float g_FloatTxData[12];

float HallTemp = 0;
float HallThetaAdd = 0;
float HallTheta = 0;
float HallTheta_Last = 0;
float HallSpeed = 0;
float HallSpeedLast = 0;
float HallSpeedtest = 0;
float alpha = 0.3;
uint8_t HallReadTemp = 0;
uint16_t ReadAngle;


void BspTIM_Init(void)
{
    TIM1->ARR = 8000-1;
	TIM1->CCR4 = 8000-2;
	HAL_TIM_Base_Start( &htim1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
    HAL_TIMEx_HallSensor_Start_IT(&htim4);
    HAL_TIM_Base_MspInit(&htim2);
    HAL_TIM_Base_Start_IT(&htim2); 
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);
	if(htim == &htim4)
	{
        
		// HallTemp = HAL_TIM_ReadCapturedValue(&htim4,TIM_CHANNEL_1);;
		// HallThetaAdd = (PI/3)/(HallTemp/10000000)/10000;
		// HallSpeed = (PI/3)/(HallTemp/10000000)*30/(2*PI);
		// HallReadTemp = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_8);
		// HallReadTemp |= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)<<1;
		// HallReadTemp |= HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)<<2;
		// if(HallReadTemp==0x05)
        // {
        //     HallTheta = 0.0f+PHASE_SHIFT_ANGLE;
        // }
        // else if(HallReadTemp==0x04)
        // {
        //     HallTheta = (PI/3.0f)+PHASE_SHIFT_ANGLE;
        // }
        // else if(HallReadTemp==0x06)
        // {
        //     HallTheta = (PI*2.0f/3.0f)+PHASE_SHIFT_ANGLE;
        // }
        // else if(HallReadTemp==0x02)
        // {
        //     HallTheta = PI+PHASE_SHIFT_ANGLE;
        // }
        // else if(HallReadTemp==0x03)
        // {
        //     HallTheta = (PI*4.0f/3.0f)+PHASE_SHIFT_ANGLE;
        // }
        // else if(HallReadTemp==0x01)
        // {
        //     HallTheta = (PI*5.0f/3.0f)+PHASE_SHIFT_ANGLE;
        // }
        // if(HallTheta<0.0f)
        // {
        //     HallTheta += 2.0f*PI;
        // }
        // else if(HallTheta>(2.0f*PI))
        // {
        //     HallTheta -= 2.0f*PI;
        // }
        
	}

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_IC_CaptureCallback could be implemented in the user file
   */
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
        float d_theta;
        AS5600_ReadAngle((uint16_t*)&ReadAngle);
        HallTheta_Last = HallTheta;
        HallTheta = ((float)(((4096 - ReadAngle) * 11) % 4096)) / 4096.0f * 2.0f * PI;
        d_theta = HallTheta - HallTheta_Last;
        if(d_theta < -PI)
        {
            d_theta += 2.0f*PI;
        }
        else if(d_theta > PI)
        {
            d_theta -= 2.0f*PI;
        }
        HallSpeedtest = d_theta*2000.0f*60.0f/(2.0f*PI);
        HallSpeed = alpha * HallSpeedtest + (1.0f - alpha) * HallSpeed;

    }else if (htim->Instance == TIM7) {
        HAL_IncTick();
    }
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


