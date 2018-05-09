
#ifndef NUCLEO_SIR_HPP
#define NUCLEO_SIR_HPP

#define SIR 2

/* == Software paramters == */

/* Speed PID */
#define PERIOD_PID (0.0052f)
#define PERIOD_POS (0.00004f)
#define NB_COEF_ERR 4
#define NB_COEF_SP 3

#define K1_ERR_L (0.002996f/2.4f)
#define K2_ERR_L (0.005659f/2.4f)
#define K3_ERR_L (0.003105f/2.4f)
#define K4_ERR_L (0.004418f/2.4f)
#define K1_SP_L (-0.947100f/2.4f)
#define K2_SP_L (0.999500f/2.4f)
#define K3_SP_L (0.947700f/2.4f)

#define K1_ERR_R (0.002996f/2.4f)
#define K2_ERR_R (0.005659f/2.4f)
#define K3_ERR_R (0.003105f/2.4f)
#define K4_ERR_R (0.004418f/2.4f)
#define K1_SP_R (-0.947100f/2.4f)
#define K2_SP_R (0.999500f/2.4f)
#define K3_SP_R (0.947700f/2.4f)

/* Motor Parameters */
#define PERIOD_PWM 0.000033f
#define MAX_DUTY 0.90f
#define DIR_FWD_L 0
#define DIR_FWD_R 0


/* == Pin connections == */

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
#define YELLOW_L PB_7
#define GREEN_L PB_6
// Right qei
#define ENCODER_TIM_RIGHT TIM2
#define YELLOW_R PA_0
#define GREEN_R PA_1
// Test qei
#define ENCODER_TIM_TEST TIM3
#define YELLOW_T PA_6
#define GREEN_T PA_7

/* Motors */
// Left motor
#define PWM_L PA_8
#define DIR_L PB_10
#define BREAK_L PA_10
// Right Motor
#define PWM_R PA_9
#define DIR_R PC_7
#define BREAK_R

/* Devices */
// AX12 (pince)
#define PINCE_RX PD_2
#define PINCE_TX PC_12
// raspberry
#define RASP_TX PC_10
#define RASP_RX PC_11





#endif
