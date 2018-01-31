/*
 * TODO
 * Documentation
 * Add a position, angle and speed pid in Motor class
 * Rework SetSpeed function to solve constant command in speed
 */


#include "mbed.h"
#include "errors.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"

Motor::Motor(PwmOut* p_pwm, DigitalOut* p_direction_0, 
		DigitalOut* p_direction_1, Qei* p_qei, Pid* p_pid, Timer* p_timer)
{
	m_pwm = p_pwm;
	m_direction_0 = p_direction_0;
	m_direction_1 = p_direction_1;
	m_qei = p_qei;
	m_pid = p_pid;
	m_timer = p_timer;
	m_pwm->period(PWM_PERIOD);
	SetSpeed(0.0f);
	m_timer->start();
}

Motor::~Motor()
{
	
}

float Motor::GetSpeed()
{
	float dt = m_timer->read();
	m_timer->reset();
	short dist = m_qei->GetQei();
	return (float)dist/dt;
}

float Motor::SetSpeed(float speed)
{
	float real_speed = GetSpeed();
	short pid_err = real_speed - speed;
	float duty_cycle = m_pid->GetPid(pid_err);
	unsigned char direction_value;
	if (duty_cycle > MIN_DUTY) {
		direction_value = DIRECTION_FORWARD;
	} else if (duty_cycle < -MIN_DUTY) {
		direction_value = DIRECTION_BACKWARD;
		duty_cycle = -duty_cycle;
	} else {
		direction_value = DIRECTION_STOP;
	}
	SetPwm(duty_cycle, direction_value);
	return real_speed;
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

