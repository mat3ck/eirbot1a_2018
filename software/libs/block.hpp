
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "mbed.h"
#include "pid.hpp"
#include "qei.hpp"
#include "motor.hpp"


class Block
{
public:
	Block(Qei& _qei, Pid& _pid, Motor& _motor, float _max_duty,
			float _period);
	~Block();
	void Reset();
	void Pause();
	void Start();
	float GetSP();
	float GetPV();
	float GetDuty();
	bool GetDir();
	bool GetBreak();
	short GetQei();
	short GetQei(short&);
	void SetSpeed(float);
	void SetBreak(bool);
	void Refresh();
private:
	float SPspeed;
	float PVspeed;
	float duty;
	short qei_value;
	float max_duty;
	float period;
	Qei& qei;
	Pid& pid;
	Motor& motor;
};


#endif
