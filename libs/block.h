
#ifndef BLOCK_H
#define BLOCK_H

#include "mbed.h"
#include "pid.h"
#include "qei.h"
#include "motor.h"

#define PERIOD_REFRESH 0.001f


class Block {
	public:
		Block(Motor*, Qei*, Pid*, Ticker*, int*);
		~Block();
		float GetSpeed();
		void SetSpeed(float);
	private:
		void Refresh();
		float _SPspeed;
		float _PVspeed;
		short _qei_value;
		int* _err;
		Motor* _motor;
		Qei* _qei;
		Pid* _pid;
		Ticker* _ticker;
};


#endif
