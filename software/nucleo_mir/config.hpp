
#ifndef NUCLEO_MIR_HPP
#define NUCLEO_MIR_HPP

/* == Software paramters == */

/* Speed PID */
#define PERIOD_PID (0.0052f)
#define PERIOD_POS (0.00004f)
#define NB_COEF_ERR 3
#define NB_COEF_SP 3
// Left
#define K1_ERR_L (0.02650f)
#define K2_ERR_L (-0.04701f)
#define K3_ERR_L (0.02060f)
#define K1_SP_L (2.1228f)
#define K2_SP_L (-1.3187f)
#define K3_SP_L (0.1959f)
// Right
#define K1_ERR_R (0.02630f)
#define K2_ERR_R (-0.04683f)
#define K3_ERR_R (0.02061f)
#define K1_SP_R (2.1370f)
#define K2_SP_R (-1.3437f)
#define K3_SP_R (0.2067f)
/* Motor Parameters */
#define PERIOD_PWM 0.000033f
#define MAX_DUTY 0.90f
#define DIR_FWD_L 0
#define DIR_FWD_R 1


/* == Pin connections == */

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
#define YELLOW_L PD_13
#define GREEN_L PD_12
// Right qei
#define ENCODER_TIM_RIGHT TIM2
#define YELLOW_R PA_0
#define GREEN_R PB_3
// Test qei
#define ENCODER_TIM_TEST TIM3
#define YELLOW_T PA_6
#define GREEN_T PC_7

/* Motors */
// Left motor
#define PWM_L PC_8
#define DIR_L PC_10
#define BREAK_L PC_11
// Right Motor
#define PWM_R PC_9
#define DIR_R PD_7
#define BREAK_R PD_6

/* Canon */
#define CANNON_RX PE_7
#define CANNON_TX PE_8

/* Display */
#define DISPLAY_RX PD_2
#define DISPLAY_TX PC_12

/* Analog pins available */
#define ADC_1 PA3
#define ADC_2 PA4
#define ADC_3 PA5
#define ADC_4 PA6
#define ADC_5 PA7
#define ADC_6 PB0
#define ADC_7 PB1
#define ADC_8 PC0
#define ADC_9 PC2
#define ADC_10 PC3
#define ADC_11 PF7
#define ADC_12 PF8
#define ADC_13 PF9
#define ADC_14 PF10
#define ADC_15 PF3
#define ADC_16 PF4
#define ADC_17 PF5

#endif
