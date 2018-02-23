
/*
 * TODO
 * Documentation
 * Test
 * Add support for TIM1 and TIM3
 * Move refreshDiff in a commun func file
 * Rework constructor to call it with pinNames
 */

#include "mbed.h"
#include "errors.h"
#include "qei.h"


Qei::Qei(TIM_Encoder_InitTypeDef* encoder, TIM_HandleTypeDef* htim, 
		TIM_TypeDef* TIMx, int* err)
{
	_encoder = encoder;
	_htim = htim;
	_TIMx = TIMx;
	TIM_MasterConfigTypeDef master_config;
	if (_TIMx == TIM2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	} else if (_TIMx == TIM4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	} else {
		*err = ERR_ENCODER_START;
	}
	
	_htim->Instance = _TIMx;
	_htim->Init.Period = MAXCOUNT_PERIOD;
	_htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	_htim->Init.Prescaler = 0;
	_htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	_encoder->EncoderMode = ENCODER_MODE;
	
	_encoder->IC1Filter = 5;
	_encoder->IC1Polarity = TIM_ICPOLARITY_RISING;
	_encoder->IC1Prescaler = TIM_ICPSC_DIV1;
	_encoder->IC1Selection = TIM_ICSELECTION_DIRECTTI;
	
	_encoder->IC2Filter = 5;
	_encoder->IC2Polarity = TIM_ICPOLARITY_RISING;
	_encoder->IC2Prescaler = TIM_ICPSC_DIV1;
	_encoder->IC2Selection = TIM_ICSELECTION_DIRECTTI;

	if (HAL_TIM_Encoder_Init(_htim, _encoder) != HAL_OK) {
		*err = ERR_ENCODER_INIT;
	}
	master_config.MasterOutputTrigger = TIM_TRGO_RESET;
	master_config.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(_htim, &master_config)
			!= HAL_OK) {
		*err = ERR_ENCODER_MASTERCONFIG;
	}
	
	GPIO_InitTypeDef GPIO_InitStruct;

	if (_TIMx == TIM2) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		GPIO_InitStruct.Pin = GPIO_PIN_0;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_3;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	} else if (_TIMx == TIM4) {
		__HAL_RCC_GPIOD_CLK_ENABLE();
		GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	} else {
		*err = ERR_ENCODER_TIMX;
	}

	if (HAL_TIM_Encoder_Start(_htim, TIM_CHANNEL_ALL) != HAL_OK) {
		*err = ERR_ENCODER_START;
	}

	_TIMx->CNT = 0;
}

Qei::~Qei()
{

}

short Qei::GetQei()
{
	return _TIMx->CNT;
}

short RefreshDiff(short* value, short new_value)
{
	short diff = *value - new_value;
	*value = new_value;
	return diff;
}
