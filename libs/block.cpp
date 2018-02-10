/*
 * TODO
 * Documentation
 * Finish Block::Refresh()
 * L49 replace 0 by previous setpoint
 */


#include "mbed.h"
#include "errors.h"
#include "pid.h"
#include "qei.h"
#include "motors.h"
#include "block.h"


Block::Block(Qei* qei, Pid* pid, Motor* motor, Ticker* ticker, int* err)
{
	_motor = motor;
	_qei = qei;
	_pid = pid;
	_ticker = ticker;
	_err = err;
	_SPspeed = 0;
	_PVspeed = 0;
	_qei_value = _qei->GetQei();
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
	static float duty_cycle = _pid->GetPid(err, 0);
	static unsigned char dir;
	if (duty_cycle > 0.0f) {
		dir = DIR_FORWARD;
	} else {
		dir = DIR_BACKWARD;
		duty_cycle = -duty_cycle;
	}
	_motor->SetPwm(duty_cycle);
	_motor->SetDirection(dir);
}

