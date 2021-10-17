/*
 * wrapper.cpp
 *
 *  Created on: Oct 16, 2021
 *      Author: under
 */
#include "wrapper.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"

Motor motor;
Encoder encoder;

double total_cnt;

void cppInit(void){
	motor.init();
	encoder.init();

}
void cppLoop(void){
	motor.setRatio(0.3);
	HAL_Delay(1000);
	motor.setRatio(-0.3);
	HAL_Delay(1000);

}

void cppFlip1ms(void){
	motor.motorCtrl();

	encoder.updateCnt();
	total_cnt = encoder.getAngle();

	encoder.clearCnt();

}



