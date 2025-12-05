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
extern uint8_t g_FloatTxData[12];
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
  UNUSED(hadc);
	if(hadc == &hadc1)
	{
		g_FloatTxData[0] = hadc1.Instance->JDR1;
		g_FloatTxData[0] = (g_FloatTxData[0] - 0x7ef)*0.02197f;
		g_FloatTxData[1] = hadc1.Instance->JDR2;
		g_FloatTxData[1] = (g_FloatTxData[1] - 0x7f5)*0.02197f;	
	}
    if (hadc == &hadc2)
    {
        /* code */
        g_FloatTxData[2] = hadc2.Instance->JDR1;
		g_FloatTxData[2] = (g_FloatTxData[2] - 0x7e8)*0.02197f;
    }
    

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

/**************************End of file********************************/


