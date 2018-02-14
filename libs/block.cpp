/*
 * TODO
 * Documentation
 */


#include "mbed.h"
#include "errors.h"
#include "pid.h"
#include "qei.h"
#include "motors.h"
#include "block.h"


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

float Block::GetSpeed()
{
	return _PVspeed;
}

void Block::SetSpeed(float speed)
{
	_SPspeed = speed;
}

void Block::Refresh()
{
	_PVspeed = RefreshDiff(&_qei_value, _qei->GetQei());
	static float err = _SPspeed - _PVspeed;
	_duty = _pid->GetPid(err, _duty);
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

