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
#include "FOC.h"
#include "BspCommUsart.h"
#include "BspTIM.h"
#include "Drv_AS5600.h"
#include "math.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp2;
extern OPAMP_HandleTypeDef hopamp3;
extern float g_FloatTxData[12];

extern float HallTemp;
extern float HallThetaAdd;
extern float HallTheta;
extern float HallSpeed;
extern float HallSpeedLast;
extern float HallSpeedtest;
extern float alpha;
extern uint8_t HallReadTemp;
extern float RealAngle;

float ADCIN[3];
float IA_Offset = 0.0f;
float IB_Offset = 0.0f;
float IC_Offset = 0.0f;
float Ia, Ib, Ic;
//static uint8_t ADC_DMA_Buffer[SNS_ADC1_CH_NUM];
float ref_Angle,Usr_Angle;
float ref_out, actual_out;

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

float normalize_angle_error(float ref, float actual) {
    float error = ref - actual;
    
    // 将差值规范到[-180, 180)
    while (error > 180.0f) error -= 360.0f;
    while (error <= -180.0f) error += 360.0f;
    
    return error;
}

// 包装函数，将处理后的误差转换为角度输入
void preprocess_angles(float *ref_out, float *actual_out, float ref_in, float actual_in) {
    float error = normalize_angle_error(ref_in, actual_in);
    
    // 保持参考角度不变，调整实际角度使其与参考角度的差等于规范化后的误差
    *ref_out = ref_in;
    *actual_out = ref_in - error;
    
    // 确保输出在[-180, 180)范围内
    if (*actual_out > 180.0f) *actual_out -= 360.0f;
    else if (*actual_out <= -180.0f) *actual_out += 360.0f;
}

// 防止输入值大于180或者小于-180
float ChangeUsrAngle(float angle)
{
    if(angle > 180.0f)
    {
        angle = angle - 360.0f;
    }
    else if(angle < -180.0f)
    {
        angle = angle + 360.0f;
    }
    return angle;
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
            
//            HallTheta = HallTheta + HallThetaAdd;
//			if(HallTheta<0.0f)
//			{
//				HallTheta += 2.0f*PI;
//			}
//			else if(HallTheta>(2.0f*PI))
//			{
//				HallTheta -= 2.0f*PI;
//			}
			rtU.Real_Theta = HallTheta;
			rtU.SpeedFd = HallSpeed;
            rtU.MechAngle = RealAngle;
            ref_Angle = ChangeUsrAngle(Usr_Angle);
            double diff = ref_Angle - RealAngle;
            rtU.AngleRef = ref_Angle - 360.0 * floor((diff + 180.0) / 360.0);
            rtU.AngleRef = ref_Angle;
			//HallSpeedtest = alpha * HallSpeed + (1 - alpha) * HallSpeedLast;
			
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in3 = hadc1.Instance->JDR2;
			adc1_in2 = hadc2.Instance->JDR1;
			rtU.ia = (adc1_in1 - IA_Offset)*0.02197f;
			rtU.ib = (adc1_in2 - IB_Offset)*0.02197f;
			rtU.ic = (adc1_in3 - IC_Offset)*0.02197f;
			FOC_step();
			TIM1->CCR1 = rtY.tABC[0];
			TIM1->CCR2 = rtY.tABC[1];
			TIM1->CCR3 = rtY.tABC[2];
            g_FloatTxData[0] = rtU.Real_Theta;
            g_FloatTxData[1] = rtU.SpeedFd;
            g_FloatTxData[2] = rtU.AngleRef;
            g_FloatTxData[3] = rtU.v_bus;
            g_FloatTxData[4] = rtDW.is_c3_FOC;
            BspUartSendJustFloatData(UsartInstance3, g_FloatTxData, 10);
		}
	}

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}

/**************************End of file********************************/


