
#ifndef NUCLEO_MIR_HPP
#define NUCLEO_MIR_HPP

/* == Software paramters == */

/* Speed PID */
#define PERIOD_PID (0.0052f)
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
#define PERIOD_PWM 0.000033f
#define MAX_DUTY 0.50f
#define DIR_FWD_L 1
#define DIR_FWD_R 1


/* == Pin connections == */

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
#define YELLOW_L PD_12
#define GREEN_L PD_13
// Right qei
#define ENCODER_TIM_RIGHT TIM2
#define YELLOW_R PB_3
#define GREEN_R PA_0
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


#endif
