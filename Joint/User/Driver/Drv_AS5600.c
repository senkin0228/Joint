/***********************************************************************************
* @file     : Drv_AS5600.c
* @brief    : 
* @details  : 
* @author   : \.rumi
* @date     : 2025-01-23
* @version  : V1.0.0
* @copyright: Copyright (c) 2050
**********************************************************************************/
#include "Drv_AS5600.h"
#include "i2c.h"

extern I2C_HandleTypeDef hi2c1;


void AS5600_Init(void)
{
    // Initialization code for AS5600 if needed
    HAL_I2C_MspInit(&hi2c1);
}

void AS5600_ReadAngle(uint16_t *angle)
{
    uint8_t reg_addr = REG_raw_ang_hi;
    uint8_t data[2] = {0};

    // Send the register address to read from
    HAL_I2C_Master_Transmit(&hi2c1, AS5600_I2C_ADDRESS, &reg_addr, 1, HAL_MAX_DELAY);
    
    // Read 2 bytes of angle data
    HAL_I2C_Master_Receive(&hi2c1, AS5600_I2C_ADDRESS, data, 2, HAL_MAX_DELAY);
    
    // Combine the two bytes into a single 16-bit value
    *angle = (data[0] << 8) | data[1];
}
    

/**************************End of file********************************/


