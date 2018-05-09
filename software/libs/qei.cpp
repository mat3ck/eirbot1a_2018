/*
 * TODO
 * Documentation
 * Add support for TIM1 and TIM3
 */

#include "qei.hpp"
#include "error.hpp"


Qei::Qei(TIM_TypeDef* _TIMx, int& err, int robot)
{
	TIMx = _TIMx;
	TIM_Encoder_InitTypeDef encoder;
	TIM_HandleTypeDef htim;
	TIM_MasterConfigTypeDef master_config;

	if (TIMx == TIM2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	} else if (TIMx == TIM3) {
		__HAL_RCC_TIM3_CLK_ENABLE();
	} else if (TIMx == TIM4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	} else {
		err = ERR_ENCODER_START;
	}
	
	htim.Instance = TIMx;
	htim.Init.Period = MAXCOUNT_PERIOD;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Prescaler = 0;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	encoder.EncoderMode = ENCODER_MODE;
	
	encoder.IC1Filter = 5;
	encoder.IC1Polarity = TIM_ICPOLARITY_RISING;
	encoder.IC1Prescaler = TIM_ICPSC_DIV1;
	encoder.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	
	encoder.IC2Filter = 5;
	encoder.IC2Polarity = TIM_ICPOLARITY_RISING;
	encoder.IC2Prescaler = TIM_ICPSC_DIV1;
	encoder.IC2Selection = TIM_ICSELECTION_DIRECTTI;

	if (HAL_TIM_Encoder_Init(&htim, &encoder) != HAL_OK) {
		err = ERR_ENCODER_INIT;
	}
	master_config.MasterOutputTrigger = TIM_TRGO_RESET;
	master_config.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim, &master_config)
			!= HAL_OK) {
		err = ERR_ENCODER_MASTERCONFIG;
	}
	
	GPIO_InitTypeDef GPIO_InitStruct;



	if (TIMx == TIM2) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
		if (robot==MIR) {
			GPIO_InitStruct.Pin = GPIO_PIN_0;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		} else if (robot==SIR){
			GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		}
		if (robot==MIR) {
			__HAL_RCC_GPIOB_CLK_ENABLE();
			GPIO_InitStruct.Pin = GPIO_PIN_3;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
			HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		}
	} else if (TIMx == TIM3) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
		if (robot==MIR) {
			GPIO_InitStruct.Pin = GPIO_PIN_6;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		} else if (robot==SIR) {
			GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
			HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		}
		if (robot==MIR) {
			__HAL_RCC_GPIOC_CLK_ENABLE();
			GPIO_InitStruct.Pin = GPIO_PIN_7;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
			HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		}
	}  else if (TIMx == TIM4) {
		if (robot==MIR) {
			__HAL_RCC_GPIOD_CLK_ENABLE();
			GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
			HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
		} else if (robot==SIR){
			__HAL_RCC_GPIOB_CLK_ENABLE();
			GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_6;
			GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
			GPIO_InitStruct.Pull = GPIO_PULLUP;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
			HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		}
	} else {
		err = ERR_ENCODER_TIMX;
	}

	if (HAL_TIM_Encoder_Start(&htim, TIM_CHANNEL_ALL) != HAL_OK) {
		err = ERR_ENCODER_START;
	}

	TIMx->CNT = 0;
}

Qei::~Qei()
{

}

void Qei::Reset()
{
	TIMx->CNT = 0;
}

short Qei::GetQei()
{
	return TIMx->CNT;
}

