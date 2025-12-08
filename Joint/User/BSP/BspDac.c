/***********************************************************************************
* @file     : BspDac.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "BspDac.h"
#include "dac.h"
#include "comp.h"
extern DAC_HandleTypeDef hdac3;
extern COMP_HandleTypeDef hcomp1;

void BspDac_Init(void)
{
    HAL_DAC_Start(&hdac3, DAC_CHANNEL_1);
    HAL_DAC_SetValue(&hdac3, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 3000);  
    HAL_COMP_Start(&hcomp1); 
}


/**************************End of file********************************/


