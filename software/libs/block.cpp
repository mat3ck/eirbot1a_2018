/*
 * TODO
 * Documentation
 * Rework constructor to call it with pinNames arguments
 * Add a reset method
 */


#include "mbed.h"
#include "error.hpp"
#include "pid.hpp"
#include "qei.hpp"
#include "motor.hpp"
#include "block.hpp"


Block::Block(Qei* qei, Pid* pid, Motor* motor, Ticker* ticker)
{
	_motor = motor;
	_qei = qei;
	_pid = pid;
	_ticker = ticker;
	_SPspeed = 0;
	_PVspeed = 0;
	_qei_value = _qei->GetQei();
	_duty = _motor->GetPwm();
	_ticker->attach(callback(this, &Block::Refresh), PERIOD_REFRESH);
}

Block::~Block()
{

}

float Block::GetSP()
{
	return _SPspeed;
}

float Block::GetPV()
{
	return _PVspeed;
}

float Block::GetPwm()
{
	return _motor->GetPwm();
}

bool Block::GetDir()
{
	return _motor->GetDir();
}

bool Block::GetBreak()
{
	return _motor->GetBreak();
}

short Block::GetQei()
{
	return _qei->GetQei();
}

void Block::SetSpeed(float speed)
{
	_SPspeed = speed;
}

void Block::SetBreak(bool br)
{
	_motor->SetBreak(br);
}

void Block::Refresh()
{
	_PVspeed = RefreshDiff(&_qei_value, _qei->GetQei());
	float err = _SPspeed - _PVspeed;
	_duty = min(_pid->GetPid(err, _duty), MAX_DUTY);
	static unsigned char dir;
	if (_duty > 0.0f) {
		dir = DIR_FORWARD;
	} else {
		dir = DIR_BACKWARD;
		_duty = -_duty;
	}
	_motor->SetDirection(dir);
	_motor->SetPwm(_duty);
}

