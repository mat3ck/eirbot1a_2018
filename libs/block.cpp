/*
 * TODO
 * Documentation
 * Finish Block::Refresh()
 */


#include "mbed.h"
#include "errors.h"
#include "pid.h"
#include "qei.h"
#include "motors.h"


Block::Block(Motor* motor, Qei* qei, Pid* pid, Ticker* ticker, int* err)
{
	_motor = motor;
	_qei = qei;
	_pid = pid;
	_ticker = ticker;
	_err = err;
	_SPspeed = 0;
	_PVspeed = 0;
	_qei_value = _qei->GetValue();
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
	static float duty_cycle = _pid->GetPid(_SPspeed - _PVspeed);
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

