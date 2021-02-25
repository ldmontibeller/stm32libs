/*
 * dataeeprom.h
 *
 *  Created on: Feb 17, 2021
 *      Author: Leonardo Drews Montibeller
 */

#ifndef DATAEEPROM_H_
#define DATAEEPROM_H_

//Specifics of data EEPROM in STM32L0 family.
#define EEPROM_BASE_ADDR 0x08080000


//Includes
#include "stm32l0xx_hal.h"

//Prototypes
void EEPROM_Read(volatile uint32_t *array, uint16_t bias, uint8_t words);
void EEPROM_Write(volatile uint32_t *array, uint16_t bias, uint8_t words);

#endif /* DATAEEPROM_H_ */
