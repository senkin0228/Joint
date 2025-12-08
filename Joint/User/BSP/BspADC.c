/***********************************************************************************
* @file     : BspADC.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "BspADC.h"
#include "adc.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp2;
extern OPAMP_HandleTypeDef hopamp3;
extern float g_FloatTxData[12];
float ADCIN[3];
float IA_Offset = 0.0f;
float IB_Offset = 0.0f;
float IC_Offset = 0.0f;
float Ia, Ib, Ic;
//static uint8_t ADC_DMA_Buffer[SNS_ADC1_CH_NUM];

void BspAdcInit(void)
{
    HAL_ADC_MspInit(&hadc1);
    HAL_ADC_MspInit(&hadc2);

    HAL_OPAMP_Start(&hopamp1);
	HAL_OPAMP_Start(&hopamp2);
	HAL_OPAMP_Start(&hopamp3);
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
    __HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_JEOC);
	__HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_EOC);
	__HAL_ADC_CLEAR_FLAG( &hadc2, ADC_FLAG_JEOC);
    HAL_ADCEx_InjectedStart_IT(&hadc1);
	HAL_ADCEx_InjectedStart(&hadc2);    
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  static uint8_t cnt=0;
  UNUSED(hadc);
	if(hadc == &hadc1)
	{
        cnt++;
        ADCIN[0] = hadc1.Instance->JDR1;
        ADCIN[1] = hadc2.Instance->JDR1;
        ADCIN[2] = hadc1.Instance->JDR2;
        IA_Offset += ADCIN[0];
        IB_Offset += ADCIN[1];
        IC_Offset += ADCIN[2];
        if(cnt >= 10)
        {
            IA_Offset /= 10.0f;
            IB_Offset /= 10.0f;
            IC_Offset /= 10.0f;
        }
		
	}
    if (hadc == &hadc2)
    {
        /* code */
        ADCIN[0] = hadc1.Instance->JDR1;
        Ia = (ADCIN[0] - IA_Offset)*0.0193359375f; //3.3/4096*24
        ADCIN[1] = hadc2.Instance->JDR1;
        Ib = (ADCIN[1] - IB_Offset)*0.0193359375f;
        ADCIN[2] = hadc1.Instance->JDR2;
        Ic = (ADCIN[2] - IC_Offset)*0.0193359375f;
        TIM1->CCR1 = 2000;
        TIM1->CCR2 = 4000;
        TIM1->CCR3 = 6000;
    }
    

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

/**************************End of file********************************/


