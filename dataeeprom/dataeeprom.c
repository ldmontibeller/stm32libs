/**
 ******************************************************************************
 * @file           : dataeeprom.c
 * @author         : Leonardo Drews Montibeller
 * @brief          : Basic usage of data EEPROM in STM32L0 family.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "dataeeprom.h"

/** Functions ----------------------------------------------------------------*/
/*
 * EEPROM_Read
 * Initializes an array  with the data stored in data EEPROM.
 * Starting at a bias address and specifying the amount of words to be read.
 */
void EEPROM_Read(volatile uint32_t *array, uint16_t bias, uint8_t words)
{
	uint32_t *addr = (uint32_t *)(EEPROM_BASE_ADDR + bias);
	for(uint8_t i = 0; i < words; i++) //number of words is limited by 255 (uint8_t)
	  {
		  array[i] = addr[i];
	  }
}

/*
 * EEPROM_Write
 * Program in data EEPROM the data stored in an array.
 * Starting at a bias address and specifying the amount of words to be written.
 */
void EEPROM_Write(volatile uint32_t *array, uint16_t bias, uint8_t words)
{
	uint32_t *addr = (uint32_t *)(EEPROM_BASE_ADDR + bias);
	HAL_FLASHEx_DATAEEPROM_Unlock();
	for(uint8_t i=0; i<words; i++)
	{
		HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, (uint32_t) &addr[i], array[i]);
	}
	HAL_FLASHEx_DATAEEPROM_Lock();
}
