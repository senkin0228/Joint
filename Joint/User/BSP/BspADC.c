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
#include "VF.h"

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
    // HAL_ADC_MspInit(&hadc1);
    // HAL_ADC_MspInit(&hadc2);

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
	static uint8_t cnt;
	static uint16_t obsever_cnt;
    uint32_t adc1_in1 = 0;
    uint32_t adc1_in2 = 0;
    uint32_t adc1_in3 = 0;  
    static uint8_t ADC_offset = 0;
    
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
	if(hadc == &hadc1)
	{
		if(ADC_offset == 0)
		{
			cnt++;
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in2 = hadc2.Instance->JDR1;
			adc1_in3 = hadc1.Instance->JDR2;
			IA_Offset += adc1_in1;
			IB_Offset += adc1_in2;
			IC_Offset += adc1_in3;
			if(cnt >= 10)
			{
				ADC_offset = 1;
				IA_Offset = IA_Offset/10;
				IB_Offset = IB_Offset/10;
				IC_Offset = IC_Offset/10;
			}
		}
		else
		{
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in3 = hadc1.Instance->JDR2;
			adc1_in2 = hadc2.Instance->JDR1;
			Ia = (adc1_in1 - IA_Offset)*0.02197f;
			Ib = (adc1_in2 - IB_Offset)*0.02197f;
			Ic = (adc1_in3 - IC_Offset)*0.02197f;
			VF_step();
			TIM1->CCR1 = rtY.tABC[0];
			TIM1->CCR2 = rtY.tABC[1];
			TIM1->CCR3 = rtY.tABC[2];
			g_FloatTxData[0] = Ia;
			g_FloatTxData[1] = Ib;
			g_FloatTxData[2] = rtY.tABC[0];
			g_FloatTxData[3] = rtY.tABC[1];
			g_FloatTxData[4] = rtY.tABC[2];
		}
	}

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

/**************************End of file********************************/


