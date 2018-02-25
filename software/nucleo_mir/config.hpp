
#ifndef NUCLEO_1_HPP
#define NUCLEO_1_HPP

/* PID coefficients */
// Left PID
#define K1_ERR_LEFT (0.0035f)
#define K2_ERR_LEFT (-0.0070f)
#define K3_ERR_LEFT (0.0035f)
#define K1_SP_LEFT (2.9824f)
#define K2_SP_LEFT (-2.9649f)
#define K3_SP_LEFT (0.9825f)
// Right PID
#define K1_ERR_RIGHT (0.0035f)
#define K2_ERR_RIGHT (-0.0070f)
#define K3_ERR_RIGHT (0.0035f)
#define K1_SP_RIGHT (2.9824f)
#define K2_SP_RIGHT (-2.9649f)
#define K3_SP_RIGHT (0.9825f)

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
// Right qei
#define ENCODER_TIM_RIGHT TIM2

/* Motors */
// Left motor
#define PIN_PWM_LEFT PC_8
#define PIN_DIR_LEFT PC_10
#define PIN_BREAK_LEFT PC_11
// Right Motor
#define PIN_PWM_RIGHT PC_9
#define PIN_DIR_RIGHT PD_7
#define PIN_BREAK_RIGHT PD_6


#endif
