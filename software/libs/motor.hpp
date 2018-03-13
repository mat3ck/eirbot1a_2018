
#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "mbed.h"
#include "common.hpp"


#define DIR_FORWARD 0
#define DIR_BACKWARD 1
#define BREAK_OFF 0
#define BREAK_ON 1


class Motor 
{
public:
	Motor(PinName _pwm, PinName _dir, PinName _br, bool _dir_fwd,
			float _period);
	~Motor();
	void Reset();
	float GetDuty();
	bool GetDir();
	bool GetBreak();
	void SetPwm(float duty_cycle);
	void SetDirection(bool dir_value);
	void SetBreak(bool br_value);
private:
	bool dir_fwd;
	PwmOut pwm;
	DigitalOut dir;
	DigitalOut br;
};


#endif
