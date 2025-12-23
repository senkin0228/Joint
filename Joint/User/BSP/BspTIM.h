/************************************************************************************
* @file     : BspTIM.h
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
***********************************************************************************/
#ifndef BSPTIM_H
#define BSPTIM_H

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif

#define PI					3.14159265358979f
#define PHASE_SHIFT_ANGLE (float)(220.0f/360.0f*2.0f*PI)

void BspTIM_Init(void);
void BspTIMGetOutput(void);


#ifdef __cplusplus
}
#endif
#endif  // BSPTIM_H
/**************************End of file********************************/

