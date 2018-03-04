
#ifndef QEI_HPP
#define QEI_HPP

#include "mbed.h"


#define MAXCOUNT_PERIOD 0xFFFF
#define ENCODER_MODE TIM_ENCODERMODE_TI12


class Qei
{
	public:
		Qei(TIM_TypeDef* _TIMx, int& err);
		~Qei();
		void Reset();
		short GetQei();
	private:
		TIM_TypeDef* TIMx;
};


#endif
