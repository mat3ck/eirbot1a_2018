
#ifndef QEI_H
#define QEI_H

#include "mbed.h"

#define MAXCOUNT_PERIOD 0xFFFF
#define ENCODER_MODE TIM_ENCODERMODE_TI12


class Qei {
	public:
		Qei(TIM_Encoder_InitTypeDef*, TIM_HandleTypeDef*, 
				TIM_TypeDef*, int*);
		~Qei();
		short GetQei();
	private:
		TIM_Encoder_InitTypeDef* _encoder;
		TIM_HandleTypeDef* _htim;
		TIM_TypeDef* _TIMx;
};

short RefreshDiff(short*, short);


#endif
