/*
 * Motor.hpp
 *
 *  Created on: Jun 11, 2021
 *      Author: Haruki Shimotori
 */

#ifndef INC_MOTOR_HPP_
#define INC_MOTOR_HPP_

#include "stm32f4xx_hal.h"

#define MAX_COUNTER_PERIOD 1799

class Motor{
private:

	int16_t temp_counter_period_;

public:

	Motor();
	void init();
	void motorCtrl(); //call by timer interruptin
	void setRatio(double);

};



#endif /* INC_MOTOR_HPP_ */
