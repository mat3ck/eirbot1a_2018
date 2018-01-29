
#ifndef QEI_H
#define QEI_H

#define MAXCOUNT_PERIOD 0xFFFF
#define ENCODER_MODE TIM_ENCODERMODE_TI12


class Qei {
	public:
		Qei(TIM_Encoder_InitTypeDef*, TIM_HandleTypeDef*, 
				TIM_TypeDef*, int*);
		~Qei();
		int GetQei();
	private:
		TIM_Encoder_InitTypeDef* m_encoder;
		TIM_HandleTypeDef* m_htim;
		TIM_TypeDef* m_TIMx;
		short m_value; 
};


#endif
