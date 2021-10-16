/*
 * wrapper.cpp
 *
 *  Created on: Oct 16, 2021
 *      Author: under
 */
#include "wrapper.hpp"
#include "Motor.hpp"

Motor motor;

void cppInit(void){
	motor.init();

}
void cppLoop(void){
	motor.setRatio(0.3);
	HAL_Delay(1000);
	motor.setRatio(-0.3);
	HAL_Delay(1000);

}

void cppFlip1ms(void){
	motor.motorCtrl();

}



