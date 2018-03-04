//
// Created by CopperBot on 03/03/2018.
//

#ifndef CANNON_HPP
#define CANNON_HPP

#include "mbed.h"
#include "comm_ax12.hpp"
#include "ax12.hpp"


#define STOP 0


class Cannon
{
public:
	Cannon(PinName rx, PinName tx);
	Cannon(PinName rx, PinName tx, char ax12_id);
	~Cannon();
	void Start();
	void Stop();
	void SetMotorSpeed(short speed, bool refreshNow);
	bool IsBallReady();
private:
	short speed;
	Comm_AX12 ax12_comm;
	AX12 ax12;
};


#endif
