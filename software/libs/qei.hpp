
#ifndef QEI_HPP
#define QEI_HPP

#include "mbed.h"


#define MAXCOUNT_PERIOD 0xFFFF
#define ENCODER_MODE TIM_ENCODERMODE_TI12


class Qei {
	public:
		Qei(TIM_TypeDef*, int*);
		~Qei();
		short GetQei();
	private:
		TIM_Encoder_InitTypeDef* encoder;
		TIM_HandleTypeDef* htim;
		TIM_TypeDef* TIMx;
};

short RefreshDiff(short*, short);


#endif
