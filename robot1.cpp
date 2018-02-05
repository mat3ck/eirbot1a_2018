
#include "mbed.h"
#include "errors.h"
#include "robot1.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"


int err = 0;

// Serial PC
Serial pc(USBTX, USBRX);
// Left Qei
TIM_Encoder_InitTypeDef* encoder_left = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* htim_left = new TIM_HandleTypeDef;
TIM_TypeDef* TIMx_left = ENCODER_TIM_LEFT;
Qei qei_left(encoder_left, htim_left, TIMx_left, &err);
//Right Qei
TIM_Encoder_InitTypeDef* encoder_right = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* htim_right = new TIM_HandleTypeDef;
TIM_TypeDef* TIMx_right = ENCODER_TIM_RIGHT;
Qei qei_right(encoder_right, htim_right, TIMx_right, &err);
// Left motor speed PID
Timer* timer_pid_left = new Timer;
Pid pid_left(PID_LEFT_KP, PID_LEFT_KI, PID_LEFT_KD, timer_pid_left);
// Right motor speed PID
Timer* timer_pid_right = new Timer;
Pid pid_right(PID_RIGHT_KP, PID_RIGHT_KI, PID_RIGHT_KD, timer_pid_right);
// Left Motor
PwmOut* pwm_left = new PwmOut(PIN_PWM_LEFT);
DigitalOut* dir0_left = new DigitalOut(PIN_DIR_LEFT1);
DigitalOut* dir1_left = new DigitalOut(PIN_DIR_LEFT2);
Timer* timer_motor_left = new Timer;
Motor motor_left(pwm_left, dir0_left, dir1_left, timer_motor_left);
// Right Motor
PwmOut* pwm_right = new PwmOut(PIN_PWM_RIGHT);
DigitalOut* dir0_right = new DigitalOut(PIN_DIR_RIGHT1);
DigitalOut* dir1_right = new DigitalOut(PIN_DIR_RIGHT2);
Timer* timer_motor_right = new Timer;
Motor motor_right(pwm_right, dir0_right, dir1_right, timer_motor_right);


int main()
{
	wait(1);
	printf("\n\n\rStarting, error code : %d\n\r", err);
}
