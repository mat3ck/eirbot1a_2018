
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
TIM_Encoder_InitTypeDef* p_encoder_left = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* p_htim_left = new TIM_HandleTypeDef;
TIM_TypeDef* p_TIMx_left = ENCODER_TIM_LEFT;
Qei qei_left(p_encoder_left, p_htim_left, p_TIMx_left, &err);
//Right Qei
TIM_Encoder_InitTypeDef* p_encoder_right = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* p_htim_right = new TIM_HandleTypeDef;
TIM_TypeDef* p_TIMx_right = ENCODER_TIM_RIGHT;
Qei qei_right(p_encoder_right, p_htim_right, p_TIMx_right, &err);
// Left motor speed PID
Timer* p_timer_pid_left = new Timer;
Pid pid_left(PID_LEFT_KP, PID_LEFT_KI, PID_LEFT_KD, p_timer_pid_left);
// Right motor speed PID
Timer* p_timer_pid_right = new Timer;
Pid pid_right(PID_RIGHT_KP, PID_RIGHT_KI, PID_RIGHT_KD, p_timer_pid_right);
// Left Motor
PwmOut* p_pwm_left = new PwmOut(PIN_PWM_LEFT);
DigitalOut* p_direction_0_left = new DigitalOut(PIN_DIR_LEFT1);
DigitalOut* p_direction_1_left = new DigitalOut(PIN_DIR_LEFT2);
Ticker* p_ticker_motor_left = new Ticker;
Motor motor_left(p_pwm_left, p_direction_0_left, p_direction_1_left, 
		&qei_left, &pid_left, p_ticker_motor_left);
// Right Motor
PwmOut* p_pwm_right = new PwmOut(PIN_PWM_RIGHT);
DigitalOut* p_direction_0_right = new DigitalOut(PIN_DIR_RIGHT1);
DigitalOut* p_direction_1_right = new DigitalOut(PIN_DIR_RIGHT2);
Ticker* p_ticker_motor_right = new Ticker;
Motor motor_right(p_pwm_right, p_direction_0_right, p_direction_1_right, 
		&qei_right, &pid_right, p_ticker_motor_right);


int main()
{

}
