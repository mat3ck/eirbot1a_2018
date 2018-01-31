
#ifndef PINS_ROBOT1_H
#define PINS_ROBOT1_H

/* Constants */
// Left PID
#define PID_LEFT_KP 0
#define PID_LEFT_KI 0
#define PID_LEFT_KD 0
// Right PID
#define PID_RIGHT_KP 0
#define PID_RIGHT_KI 0
#define PID_RIGHT_KD 0

/* Encoders */
// Left qei
#define ENCODER_TIM_LEFT TIM4
// Right qei
#define ENCODER_TIM_RIGHT TIM2

/* Motors */
// Left motor
#define PIN_PWM_LEFT PC_8
#define PIN_DIR_LEFT1 PC_10
#define PIN_DIR_LEFT2 PC_11
// Right Motor
#define PIN_PWM_RIGHT PC_9
#define PIN_DIR_RIGHT1 PD_7
#define PIN_DIR_RIGHT2 PD_6


#endif
