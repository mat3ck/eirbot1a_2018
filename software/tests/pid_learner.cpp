// DO NOT USE
// MOTORS DIRECTION BLINK WHEN ROBOT IS STOPPED0P
#include "mbed.h"
#include "errors.h"
#include "robot1.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"


int err = 0;
Timer tim;

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


float min(float a, float b)
{
	return (a<b ? a:b);
}

void LearnKp()
{
	float speed = 0;
	float kpl = 1.0f/4096.0f;
	float kpr = 1.0f/4096.0f;
	pc.printf("SPEED : %f\t\tkpl : %f\t\t kpr : %f\n\r",
		speed, kpl, kpr);
	float speedl;
	float speedr;
	float rl;
	float rr;
	while (speed < 8192) {
		speed += 256;
		motor_left.SetSpeed(speed);
		motor_right.SetSpeed(speed);
		wait(0.5);
		speedl = motor_left.GetSpeed();
		speedr = motor_right.GetSpeed();
		rl = speed/speedl;
		rr = speed/speedr;
		while ((rl<0.93 || rl>0.97) || (rr<0.93 || rr>0.97)) {
			kpl *= min(rl, 1.3);
			kpr *= min(rr, 1.3);
			pid_left.SetPid(kpl, 0.0f, 0.0f);
			pid_right.SetPid(kpr, 0.0f, 0.0f);
			wait(0.5);
			pc.printf("SPEED %f\tDUTYL %f\t DUTYR %f\tkpl %f\tkpr %f\r",
				speed, p_pwm_left->read(), p_pwm_right->read(),
				kpl, kpr);
		}
		pc.printf("\n\rSPEED : %f\t\tkpl : %f\t\t kpr : %f\n\r",
				speed, kpl, kpr);
	}
	pc.printf("FINALS : kpl : %f\t\t kpr : %f\n\r", kpl, kpr);
}

int main()
{
	pc.printf("\n\n\rStarting 2 : error %d\n\r", err);
	wait(1);
	LearnKp();
}
