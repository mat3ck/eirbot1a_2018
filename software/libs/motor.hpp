
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


class Motor {
	public:
		Motor(PwmOut*, DigitalOut*, DigitalOut*, bool);
		~Motor();
		float GetPwm();
		bool GetDir();
		bool GetBreak();
		void SetPwm(float);
		void SetDirection(bool);
		void SetBreak(bool);
	private:
		bool _dir_fwd;
		PwmOut* _pwm;
		DigitalOut* _dir;
		DigitalOut* _break;
};


#endif
