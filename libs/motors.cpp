/*
 * TODO
 * Documentation
 */


#include "mbed.h"
#include "errors.h"
#include "motors.h"


struct s_motor new_motor(PwmOut* p_pwm, DigitalOut* p_direction_0, DigitalOut* p_direction_1)
{
	struct s_motor motor;
	motor.p_pwm = p_pwm;
	motor.p_direction_0 = p_direction_0;
	motor.p_direction_1 = p_direction_1;
	return motor;
}

void init_motor(struct s_motor* p_motor_left, struct s_motor* p_motor_right)
{
	p_motor_left->p_pwm->period(PWM_PERIOD);
	p_motor_right->p_pwm->period(PWM_PERIOD);
	set_direction(p_motor_left, DIRECTION_STOP);
	set_direction(p_motor_right, DIRECTION_STOP);
}

int set_pwm(struct s_motor* p_motor, float duty_cycle)
{
	int error = NO_ERROR;
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
		error = ERR_PWM_OVERVALUE;
	}
	p_motor->p_pwm->write(duty_cycle);
	return error;
}

int set_direction(struct s_motor* p_motor, unsigned char direction_value)
{
	if (direction_value > 3) {
		return ERR_DIRECTION_VALUE;
	}
	*(p_motor->p_direction_0) = direction_value & 1;
	*(p_motor->p_direction_1) = direction_value & 2;
	return NO_ERROR;
}

void full_stop(struct s_motor* p_motor_left, struct s_motor* p_motor_right)
{
	set_pwm(p_motor_left, 0.0f);
	set_pwm(p_motor_right, 0.0f);
}
