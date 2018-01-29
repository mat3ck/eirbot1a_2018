
#ifndef MOTORS_H
#define MOTORS_H

#define PWM_PERIOD 0.000033
#define MAX_DUTY 0.95

#define DIRECTION_STOP 0
#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD 2
#define DIRECTION_BREAK 3


class Motor {
	public:
		Motor(PwmOut*, DigitalOut*, DigitalOut*);
		~Motor();
		int SetPwm(float, unsigned char);
	private:
		PwmOut* m_pwm;
		DigitalOut* m_direction_0;
		DigitalOut* m_direction_1;
};


#endif
