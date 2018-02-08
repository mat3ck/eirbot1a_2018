/*
 * TODO
 * Documentation
 */


#include "mbed.h"
#include "errors.h"
#include "motors.h"

Motor::Motor(PwmOut* pwm, DigitalOut* dir, DigitalOut* br)
{
	_pwm = pwm;
	_dir = dir;
	_break = br;
	_pwm->period(PERIOD_PWM);
	SetPwm(0.0f);
	SetDirection(DIR_FORWARD);
	SetBreak(BREAK_OFF);
}

Motor::~Motor()
{
	
}

void Motor::SetPwm(float duty_cycle)
{
	float duty = min(duty_cycle, MAX_DUTY);
	_pwm->write(duty);
}

void Motor::SetDirection(unsigned char dir_value)
{
	*_dir = dir_value;
}

void Motor::SetBreak(bool br)
{
	*_break = br;
}

