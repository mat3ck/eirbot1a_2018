/*
 * TODO
 * Documentation
 * Put other objects (SetSpeed, Tickers..) in other classes, functions..
 */


#include "mbed.h"
#include "errors.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"

Motor::Motor(PwmOut* pwm, DigitalOut* dir0, DigitalOut* dir1)
{
	_pwm = pwm;
	_dir0 = dir0;
	_dir1 = dir1;

	_duty = 0;
	_dir = DIR_STOP;
	_pwm->period(PERIOD_PWM);
	SetPwm(0.0f);
	SetDirection(DIR_STOP);
}

Motor::~Motor()
{
	
}

void Motor::SetPwm(float duty_cycle)
{
	_duty = min(duty_cycle, MAX_DUTY);
	_pwm->write(_duty);
}

void Motor::SetDirection(unsigned char dir_value)
{
	_dir = dir_value;
	*_dir0 = _dir & 1;
	*_dir1 = _dir & 2;
}
