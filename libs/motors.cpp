/*
 * TODO
 * Documentation
 * Make the class more lighter to just contains motor object
 * Put other objects (SetSpeed, Tickers..) in other classes, functions..
 */


#include "mbed.h"
#include "errors.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"

Motor::Motor(PwmOut* pwm, DigitalOut* direction0, DigitalOut* direction1,
		Qei* qei, Pid* pid, Ticker* ticker, Timer* timer)
{
	_qei_value = 0;
	_pwm = pwm;
	_direction0 = direction0;
	_direction1 = direction1;
	_qei = qei;
	_pid = pid;
	_ticker = ticker;
	_timer = timer;
	_pwm->period(PERIOD_PWM);
	SetSpeed(0.0f);
	SetDirection(DIRECTION_STOP);
	_ticker->attach(callback(this, &Motor::Refresh), PERIOD_REFRESH);
	_timer->start();
}

Motor::~Motor()
{
	
}

float Motor::GetSpeed()
{
	return _PV_speed;
}

void Motor::SetSpeed(float speed)
{
	_SP_speed = speed;
}

void Motor::Refresh()
{
	short dist = RefreshDiff(&_qei_value, _qei->GetQei());
	_PV_speed = (float)dist/PERIOD_REFRESH;
	float duty_cycle = _pid->GetPid(_SP_speed-_PV_speed);
	unsigned char direction_value;
	if (duty_cycle > MIN_DUTY) {
		direction_value = DIRECTION_FORWARD;
	} else if (duty_cycle < -MIN_DUTY) {
		direction_value = DIRECTION_BACKWARD;
		duty_cycle = -duty_cycle;
	} else {
		direction_value = DIRECTION_STOP;
	}
	SetPwm(duty_cycle);
	SetDirection(direction_value);
}

void Motor::SetPwm(float duty_cycle)
{
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
	}
	_pwm->write(duty_cycle);
}

void Motor::SetDirection(unsigned char direction_value)
{
	if ((direction_value == DIRECTION_STOP || _direction == DIRECTION_STOP)
			&& _timer->read() > 0.2) {
		_direction = direction_value;
		*_direction0 = _direction & 1;
		*_direction1 = _direction & 2;
	}
}
