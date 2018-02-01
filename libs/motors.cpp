/*
 * TODO
 * Documentation
 * Add a position, angle and speed pid in Motor class
 * Rework SetSpeed function to solve constant command in speed
 */


#include "mbed.h"
#include "errors.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"

Motor::Motor(PwmOut *p_pwm, DigitalOut *p_direction0, DigitalOut *p_direction1,
		Qei *p_qei, Pid *p_pid, Ticker *p_ticker)
{
	_qei_value = 0;
	_pwm = p_pwm;
	_direction0 = p_direction0;
	_direction1 = p_direction1;
	_qei = p_qei;
	_pid = p_pid;
	_ticker = p_ticker;
	_pwm->period(PERIOD_PWM);
	SetSpeed(0.0f);
	_ticker->attach(callback(this, &Motor::Refresh), PERIOD_REFRESH);
}

Motor::~Motor()
{
	
}

float Motor::GetSpeed()
{
	return _PV_speed;
	return _SP_speed;
}

void Motor::SetSpeed(float speed)
{
	_SP_speed = speed;
}

void Motor::Refresh()
{
	short dist = RefreshDiff(&_qei_value, _qei->GetQei());
	_PV_speed = (float)dist/PERIOD_REFRESH;
	float duty_cycle = _pid->GetPid(_PV_speed - _SP_speed);
	unsigned char direction_value;
	if (duty_cycle > MIN_DUTY) {
		direction_value = DIRECTION_FORWARD;
	} else if (duty_cycle < -MIN_DUTY) {
		direction_value = DIRECTION_BACKWARD;
		duty_cycle = -duty_cycle;
	} else if (duty_cycle == NAN) {
		direction_value = DIRECTION_BREAK;
	} else {
		direction_value = DIRECTION_STOP;
	}
	SetPwm(duty_cycle, direction_value);
}

void Motor::SetPwm(float duty_cycle, unsigned char direction_value)
{
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
	}
	_pwm->write(duty_cycle);
	*_direction0 = direction_value & 1;
	*_direction1 = direction_value & 2;
}

