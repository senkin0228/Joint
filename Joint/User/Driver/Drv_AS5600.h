/************************************************************************************
* @file     : Drv_AS5600.h
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
***********************************************************************************/
#ifndef DRV_AS5600_H
#define DRV_AS5600_H

#include <string.h>
#include <stdbool.h>
#include "stdint.h"

#ifdef __cplusplus
#include <iostream>
extern "C" {
#endif

#define AS5600_I2C_ADDRESS       0x36 << 1  // 7-bit address shifted for HAL I2C functions


typedef enum
{
/* set i2c address */ 
  REG_zmco = 0x00,
  REG_zpos_hi = 0x01,
  REG_zpos_lo = 0x02,
  REG_mpos_hi = 0x03,
  REG_mpos_lo = 0x04,
  REG_mang_hi = 0x05,
  REG_mang_lo = 0x06,
  REG_conf_hi = 0x07,    
  REG_conf_lo = 0x08,
  REG_raw_ang_hi = 0x0c,
  REG_raw_ang_lo = 0x0d,
  REG_ang_hi = 0x0e,
  REG_ang_lo = 0x0f,
  REG_stat = 0x0b,
  REG_agc = 0x1a,
  REG_mag_hi = 0x1b,
  REG_mag_lo = 0x1c,
  REG_burn = 0xff
}AMS5600_Registers;

void AS5600_Init(void);
void AS5600_ReadAngle(uint16_t *angle);


#ifdef __cplusplus
}
#endif
#endif  // DRV_AS5600_H
/**************************End of file********************************/

