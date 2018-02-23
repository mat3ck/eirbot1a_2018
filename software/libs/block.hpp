
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "mbed.h"
#include "pid.hpp"
#include "qei.hpp"
#include "motor.hpp"


#define PERIOD_REFRESH 0.0052f


class Block {
	public:
		Block(Qei*, Pid*, Motor*, Ticker*);
		~Block();
		float GetSP();
		float GetPV();
		float GetPwm();
		bool GetDir();
		bool GetBreak();
		short GetQei();
		void SetSpeed(float);
		void SetBreak(bool);
	private:
		void Refresh();
		float _SPspeed;
		float _PVspeed;
		short _qei_value;
		float _duty;
		Qei* _qei;
		Pid* _pid;
		Motor* _motor;
		Ticker* _ticker;
};


#endif
