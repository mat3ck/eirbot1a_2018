
/*
 * TODO
 * Documentation
 * Test
 * Add support for TIM1 and TIM3
 */

#include "mbed.h"
#include "errors.h"
#include "qei.h"


Qei::Qei(TIM_Encoder_InitTypeDef* p_encoder, TIM_HandleTypeDef* p_htim, 
		TIM_TypeDef* p_TIMx, int* p_err)
{
	if (m_TIMx == TIM2) {
		__HAL_RCC_TIM2_CLK_ENABLE();
	} else if (m_TIMx == TIM4) {
		__HAL_RCC_TIM4_CLK_ENABLE();
	}
	m_encoder = p_encoder;
	m_htim = p_htim;
	m_TIMx = p_TIMx;
	TIM_MasterConfigTypeDef master_config;
	
	m_htim->Instance = m_TIMx;
	m_htim->Init.Period = MAXCOUNT_PERIOD;
	m_htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	m_htim->Init.Prescaler = 0;
	m_htim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

	m_encoder->EncoderMode = ENCODER_MODE;
	
	m_encoder->IC1Filter = 5;
	m_encoder->IC1Polarity = TIM_ICPOLARITY_RISING;
	m_encoder->IC1Prescaler = TIM_ICPSC_DIV1;
	m_encoder->IC1Selection = TIM_ICSELECTION_DIRECTTI;
	
	m_encoder->IC2Filter = 5;
	m_encoder->IC2Polarity = TIM_ICPOLARITY_RISING;
	m_encoder->IC2Prescaler = TIM_ICPSC_DIV1;
	m_encoder->IC2Selection = TIM_ICSELECTION_DIRECTTI;

	if (HAL_TIM_Encoder_Init(m_htim, m_encoder) != HAL_OK) {
		*p_err = ERR_ENCODER_INIT;
	}
	master_config.MasterOutputTrigger = TIM_TRGO_RESET;
	master_config.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(m_htim, &master_config)
			!= HAL_OK) {
		*p_err = ERR_ENCODER_MASTERCONFIG;
	}
	
	GPIO_InitTypeDef GPIO_InitStruct;

	if (m_TIMx == TIM2) {
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
	} else if (m_TIMx == TIM4) {
		__HAL_RCC_GPIOD_CLK_ENABLE();
		GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	} else {
		*p_err = ERR_ENCODER_TIMX;
	}

	if (HAL_TIM_Encoder_Start(m_htim, TIM_CHANNEL_ALL) != HAL_OK) {
		*p_err = ERR_ENCODER_START;
	}

	m_TIMx->CNT = 0;
}

Qei::~Qei()
{

}

int Qei::GetQei()
{
	short new_value = m_TIMx->CNT;
	int qei_value = new_value - m_value;
	m_value = new_value;
	return qei_value;
}

