
#ifndef MOTORS_H
#define MOTORS_H

#include "mbed.h"
#include "qei.h"
#include "pid.h"

#define PERIOD_REFRESH 0.001f
#define PERIOD_PWM 0.000033f
#define MIN_DUTY 0.01f
#define MAX_DUTY 0.95f

#define DIRECTION_STOP 0
#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD 2
#define DIRECTION_BREAK 3


class Motor {
	public:
		Motor(PwmOut*, DigitalOut*, DigitalOut*, Qei*, Pid*, Ticker*);
		~Motor();
		float GetSpeed();
		void SetSpeed(float);
	protected:
		void Refresh();
	private:
		void SetPwm(float, unsigned char);
		float m_SP_speed;
		float m_PV_speed;
		short m_qei_value;
		PwmOut* m_pwm;
		DigitalOut* m_direction0;
		DigitalOut* m_direction1;
		Qei* m_qei;
		Pid* m_pid;
		Ticker* m_ticker;
};


#endif
