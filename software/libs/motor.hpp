
#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "mbed.h"
#include "common.hpp"


#define PERIOD_PWM 0.000033f
#define MAX_DUTY 0.50f

#define DIR_FORWARD 0
#define DIR_BACKWARD 1
#define BREAK_OFF 0
#define BREAK_ON 1


class Motor 
{
public:
	Motor(PinName pwm, PinName dir, PinName br, bool _dir_fwd);
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
