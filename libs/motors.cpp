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

void Motor::SetPwm(float duty_cycle, int* err)
{
	if (abs(_duty - duty_cycle) > 0.5) {
		*err = ERR_SETPWM
	}
	_duty = min(duty_cycle, MAX_DUTY);
	_pwm->write(_duty);
}

void Motor::SetDirection(unsigned char dir_value, int* err)
{
	if (dir_value != _dir) {
		if (_timer->read() > 0.20f && _duty < 0.20f) {
			_dir = dir_value;
		} else {
			_dir = DIR_STOP;
			*err = ERR_SETDIR;
		}
	}
	*_dir0 = _dir & 1;
	*_dir1 = _dir & 2;
}

