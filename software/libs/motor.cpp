/*
 * TODO
 * Documentation
 * Create LMD18200 and L298 class inheritant from Motor
 * Rework constructor to call it with pinNames
 */


#include "mbed.h"
#include "errors.h"
#include "motors.h"

Motor::Motor(PwmOut* pwm, DigitalOut* dir, DigitalOut* br, bool dir_fwd)
{
	_dir_fwd = dir_fwd;
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

float Motor::GetPwm()
{
	return _pwm->read();
}

bool Motor::GetDir()
{
	return *_dir;
}

bool Motor::GetBreak()
{
	return *_break;
}

void Motor::SetPwm(float duty_cycle)
{
	float duty = min(duty_cycle, MAX_DUTY);
	_pwm->write(duty);
}

void Motor::SetDirection(bool dir_value)
{
	*_dir = (dir_value && !_dir_fwd) || (!dir_value && _dir_fwd);
}

void Motor::SetBreak(bool br)
{
	*_break = br;
}

