/*
 * Motor.cpp
 *
 *  Created on: Jun 11, 2021
 *      Author: Haruki Shimotori
 */



#include "Motor.hpp"
#include "G_variables.h"


Motor::Motor() : temp_counter_period_(0){}

void Motor::init()
{
	//PWM start
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

}

void Motor::motorCtrl()
{
	uint16_t counter_period;

	if(temp_counter_period_ < 0) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
		counter_period = -1 * temp_counter_period_;
	}
	else{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
		counter_period = temp_counter_period_;
	}

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, counter_period);
}

void Motor::setRatio(double ratio)
{
	if(ratio > 1) ratio = 1;
	else if(ratio < -1) ratio = -1;

	temp_counter_period_ = (int)((double)MAX_COUNTER_PERIOD * ratio);

}
