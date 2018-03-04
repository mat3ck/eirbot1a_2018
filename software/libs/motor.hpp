
#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "mbed.h"


#define PERIOD_PWM 0.000033f
#define MAX_DUTY 0.20f

#define DIR_FORWARD 0
#define DIR_BACKWARD 1
#define BREAK_OFF 0
#define BREAK_ON 1

#define min(x, y) ((x)<(y) ? (x) : (y))


class Motor 
{
public:
	Motor(PinName pwm, PinName dir, PinName br, bool);
	~Motor();
	void Reset();
	float GetPwm();
	bool GetDir();
	bool GetBreak();
	void SetPwm(float);
	void SetDirection(bool);
	void SetBreak(bool);
private:
	bool dir_fwd;
	PwmOut pwm;
	DigitalOut dir;
	DigitalOut br;
};


#endif
