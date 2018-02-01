
/*
 * TODO
 * Documentation
 * Add xy and angle pid, maybe speed pid for each motor
 * Add PidLearner class to auto set pid coef respecting restrictions
 */

#include "mbed.h"
#include "errors.h"
#include "pid.h"


Pid::Pid(float kp, float ki, float kd, Timer* p_timer)
{
	_kp = kp;
	_ki = ki;
	_kd = kd;
	_timer = p_timer;
	_timer->start();
}

Pid::~Pid()
{

}

float Pid::GetPid(float err)
{
	RefreshPid(err);
	return _kp*_err + _ki*_ierr + _kd*_derr;
}

void Pid::SetPid(float kp, float ki, float kd)
{
	_kp = kp;
	_ki = ki;
	_kd = kd;
}

void Pid::RefreshPid(float err)
{
	float dt = _timer->read();
	_timer->reset();
	_ierr += err*dt;
	_derr = (err-_err)/dt;
	_err = err;
}
