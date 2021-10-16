/*
 * G_variables.h
 *
 *  Created on: 2021/06/10
 *      Author: under
 */

#ifndef INC_G_VARIABLES_H_
#define INC_G_VARIABLES_H_

#include "Macro.h"

#ifdef DEF_EXTERN
// -----auto generate variables ------//
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c3;

SPI_HandleTypeDef hspi3;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim4;
#else

// -----auto generate variables ------//
extern ADC_HandleTypeDef hadc1;

extern I2C_HandleTypeDef hi2c3;

extern SPI_HandleTypeDef hspi3;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;

#endif

#endif /* INC_G_VARIABLES_H_ */
