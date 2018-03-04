
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "mbed.h"
#include "pid.hpp"
#include "qei.hpp"
#include "motor.hpp"


#define PERIOD_REFRESH 0.0052f


class Block
{
public:
	Block(Qei& _qei, Pid& _pid, Motor& _motor);
	~Block();
	void Reset();
	void Start();
	float GetSP();
	float GetPV();
	float GetPwm();
	bool GetDir();
	bool GetBreak();
	short GetQei();
	short GetQei(short*);
	void SetSpeed(float);
	void SetBreak(bool);
private:
	void Refresh();
	float SPspeed;
	float PVspeed;
	float duty;
	short qei_value;
	Qei& qei;
	Pid& pid;
	Motor& motor;
	Ticker ticker;
};


#endif
