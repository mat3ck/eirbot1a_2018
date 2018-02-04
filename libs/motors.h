
#ifndef MOTORS_H
#define MOTORS_H

#include "mbed.h"
#include "qei.h"
#include "pid.h"

#define PERIOD_REFRESH 0.001f
#define PERIOD_PWM 0.000033f
#define MIN_DUTY 0.05f
#define MAX_DUTY 0.50f

#define DIRECTION_STOP 0
#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD 2
#define DIRECTION_BREAK 3

#define AbsMin(x, y) (abs(x)<abs(y) ? (x) : (y))

class Motor {
	public:
		Motor(PwmOut*, DigitalOut*, DigitalOut*, Qei*, Pid*, Ticker*, Timer*);
		~Motor();
		float GetSpeed();
		void SetSpeed(float);
	private:
		void Refresh();
		void SetPwm(float);
		void SetDirection(unsigned char);
		float _SP_speed;
		float _PV_speed;
		float _duty;
		unsigned short _direction;
		short _qei_value;
		PwmOut* _pwm;
		DigitalOut* _direction0;
		DigitalOut* _direction1;
		Qei* _qei;
		Pid* _pid;
		Ticker* _ticker;
		Timer* _timer;
};


#endif
