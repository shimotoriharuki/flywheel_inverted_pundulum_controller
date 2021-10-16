/*
 * Encoder.cpp
 *
 *  Created on: Jun 13, 2021
 *      Author: under
 */

#include "Encoder.hpp"
#include "G_variables.h"

#define MAX_ENCODER_CNT 65535
#define CNT_OFFSET 32768
#define WHEEL_RADIUS 11 //[mm]
#define PI 3.1415926535
#define ENCODER_RESOLUTION 4096
#define REDUCTION_RATIO 0.35 //Gear reduction ratio

float monitor_cnt;

Encoder::Encoder() : cnt_(0), total_cnt_(0){}

void Encoder::init()
{
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
	TIM4 -> CNT = CNT_OFFSET;
}

void Encoder::updateCnt()
{
	cnt_ = (float(CNT_OFFSET) - float(TIM4 -> CNT));
	total_cnt_ += cnt_;
}

void Encoder::getCnt(double &cnt)
{
	cnt = cnt_;
}

void Encoder::clearCnt()
{
	cnt_ = 0;
	TIM4 -> CNT = CNT_OFFSET;
}

double Encoder::getTotalCnt()
{
	return total_cnt_;
}

void Encoder::clearTotalCnt()
{
	total_cnt_ = 0;
}
