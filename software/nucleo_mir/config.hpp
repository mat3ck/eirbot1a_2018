
#ifndef NUCLEO_1_HPP
#define NUCLEO_1_HPP

/* == Software paramters == */

/* Speed PID coefficients */
#define NB_COEF_ERR 4
#define NB_COEF_SP 3
#define K1_ERR (0.002996f/2.4f)
#define K2_ERR (0.005659f/2.4f)
#define K3_ERR (0.003105f/2.4f)
#define K4_ERR (0.004418f/2.4f)
#define K1_SP (-0.947100f/2.4f)
#define K2_SP (0.999500f/2.4f)
#define K3_SP (0.947700f/2.4f)
/* Motor Parameters */
#define DIR_FWD_LEFT 1
#define DIR_FWD_RIGHT 1


/* == Pin connections == */

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
