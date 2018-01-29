/*
 * TODO
 * Documentation
 */


#include "mbed.h"
#include "errors.h"
#include "motors.h"

Motor::Motor(PwmOut* p_pwm, DigitalOut* p_direction_0, 
		DigitalOut* p_direction_1)
{
	m_pwm = p_pwm;
	m_direction_0 = p_direction_0;
	m_direction_1 = p_direction_1;
	SetPwm(0.0f, 0);
}

Motor::~Motor()
{
	;
}

int Motor::SetPwm(float duty_cycle, unsigned char direction_value)
{
	int error = NO_ERROR;
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
		error = ERR_PWM_OVERVALUE;
	}
	if (direction_value > 3) {
		direction_value = DIRECTION_STOP;
		error = ERR_DIRECTION_VALUE;
	}
	m_pwm->write(duty_cycle);
	*m_direction_0 = direction_value & 1;
	*m_direction_1 = direction_value & 2;
	return error;
}

