/*
 * TODO
 * Documentation
 */

#ifndef ERROR_INCLUDE
#define ERROR_INCLUDE
#include "error.h"
#endif

#include "motor.h"

struct s_motor
{
	PwmOut pwm;
	DigitalOut direction_0;
	DigitalOut direction_1;
};

struct s_motor new_motor(PwmOut pwm, DigitalOut direction_0, DigitalOut direction_1)
{
	struct s_motor motor;
	motor.pwm = pwm;
	motor.direction_0 = direction_0;
	motor.direction_1 = direction_1;
}

void init_motor(struct s_motor* motor_left, struct s_motor* motor_right)
{
	motor_left->pwm.period(PWM_PERIOD);
	motor_right->pwm.period(PWM_PERIOD);
	set_sens(motor_left, DIRECTION_STOP);
	set_sens(motor_right, DIRECTION_STOP);
}

int set_pwm(struct s_motor* motor, float* duty_cycle)
{
	int error = NO_ERROR;
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
		error = ERROR_PWM_OVERVALUE;
	}
	motor->pwm.write(duty_cycle);
	return error;
}

int set_direction(struct s_motor* motor, unsigned char* direction_value)
{
	if (direction_value > 3) return ERROR_DIRECTION_VALUE;
	motor->direction_0 = direction_value & 1;
	motor->direction_1 = direction_value & 2;
	return NO_ERROR;
}

void full_stop(struct s_motor* motor_left, struct s_motor* motor_right)
{
	set_pwm(motor_left, 0.0);
	set_pwm(motor_right, 0.0);
}
