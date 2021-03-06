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
//#define CNT_OFFSET 0
#define PI 3.1415926535
#define ENCODER_RESOLUTION 1024
#define REDUCTION_RATIO 1 //Gear reduction ratio 0.35
#define ANGLE_PER_CNT ((2 * PI / ENCODER_RESOLUTION) * REDUCTION_RATIO)

Encoder::Encoder() : cnt_(0), total_cnt_(0), angle_(0){}

void Encoder::init()
{
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
	TIM4 -> CNT = CNT_OFFSET;
	cnt_ = 0;
	total_cnt_ = 0;
	angle_ = 0;
}

void Encoder::updateCnt()
{
	cnt_ = (float(CNT_OFFSET) - float(TIM4 -> CNT));
	total_cnt_ += cnt_;
	angle_ += cnt_ * ANGLE_PER_CNT;
}

double Encoder::getCnt()
{
	return cnt_;
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

double Encoder::getAngle()
{
	return angle_;
}

void Encoder::clearAngle()
{
	angle_ = 0;
}
