
#ifndef NUCLEO_1_HPP
#define NUCLEO_1_HPP

/* PID coefficients */
#define NB_COEF 3
// Left PID
#define K1_ERR_LEFT (0.002996f/2.4f)
#define K2_ERR_LEFT (0.005659f/2.4f)
#define K3_ERR_LEFT (0.003105f/2.4f)
#define K4_ERR_LEFT (0.004418f/2.4f)
#define K1_SP_LEFT (-0.947100f/2.4f)
#define K2_SP_LEFT (0.999500f/2.4f)
#define K3_SP_LEFT (0.947700f/2.4f)
// Right PID
#define K1_ERR_RIGHT (0.002996f/2.4f)
#define K2_ERR_RIGHT (0.005659f/2.4f)
#define K3_ERR_RIGHT (0.003105f/2.4f)
#define K4_ERR_RIGHT (0.004418f/2.4f)
#define K1_SP_RIGHT (-0.947100f/2.4f)
#define K2_SP_RIGHT (0.999500f/2.4f)
#define K3_SP_RIGHT (0.947700f/2.4f)
/*
#define K1_ERR_RIGHT (0.0035f)
#define K2_ERR_RIGHT (-0.0070f)
#define K3_ERR_RIGHT (0.0035f)
#define K1_SP_RIGHT (2.9824f)
#define K2_SP_RIGHT (-2.9649f)
#define K3_SP_RIGHT (0.9825f)
*/

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
#define YELLOW_L PD12
#define GREEN_L PD13
// Right qei
#define ENCODER_TIM_RIGHT TIM2
#define YELLOW_R PB03
#define GREEN_R PA00

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
