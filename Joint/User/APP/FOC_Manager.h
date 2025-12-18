/************************************************************************************
* @file     : FOC_Manager.h
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
***********************************************************************************/
#ifndef FOC_MANAGER_H
#define FOC_MANAGER_H

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif


void FOC_Manager_Process(uint16_t TaskTick);
void FOC_Manager_Init(void);


#ifdef __cplusplus
}
#endif
#endif  // FOC_MANAGER_H
/**************************End of file********************************/

