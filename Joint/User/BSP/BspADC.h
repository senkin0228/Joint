/************************************************************************************
* @file     : BspADC.h
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
***********************************************************************************/
#ifndef BSP_ADC_H
#define BSP_ADC_H

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif

#define SNS_ADC1_CH_NUM    5


void BspAdcInit(void);
#ifdef __cplusplus
}
#endif
#endif  // BSP_ADC_H
/**************************End of file********************************/

