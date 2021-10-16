/*
 * Encoder.hpp
 *
 *  Created on: Jun 13, 2021
 *      Author: under
 */

#ifndef INC_ENCODER_HPP_
#define INC_ENCODER_HPP_

#include "stm32f4xx_hal.h"

class Encoder{

private:
	double cnt_;
	double total_cnt_;

public:
	Encoder();
	void init();
	void updateCnt();
	void getCnt(double &);
	void clearCnt();
	double getTotalCnt();
	void clearTotalCnt();
};

#endif /* INC_ENCODER_HPP_ */
