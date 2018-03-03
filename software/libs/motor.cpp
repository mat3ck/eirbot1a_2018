/*
 * TODO
 * Documentation
 * Create LMD18200 and L298 class inheritant from Motor
 */

#include "motor.hpp"


Motor::Motor(PinName _pwm, PinName _dir, PinName _break, bool _dir_fwd)
{
	dir_fwd = _dir_fwd;
	pin_pwm = new PwmOut(_pwm);
	pin_dir = new DigitalOut(_dir);
	pin_break = new DigitalOut(_break);
	pin_pwm->period(PERIOD_PWM);
	SetPwm(0.0f);
	SetDirection(DIR_FORWARD);
	SetBreak(BREAK_OFF);
}

Motor::~Motor()
{
	
}

void Motor::Reset()
{
	SetPwm(0.0f);
	SetDirection(DIR_FORWARD);
	SetBreak(BREAK_OFF);
}

float Motor::GetPwm()
{
	return pin_pwm->read();
}

bool Motor::GetDir()
{
	return *pin_dir;
}

bool Motor::GetBreak()
{
	return *pin_break;
}

void Motor::SetPwm(float duty_cycle)
{
	float duty = min(duty_cycle, MAX_DUTY);
	pin_pwm->write(duty);
}

void Motor::SetDirection(bool dir_value)
{
	*pin_dir = (dir_value && !dir_fwd) || (!dir_value && dir_fwd);
}

void Motor::SetBreak(bool br)
{
	*pin_break = br;
}

