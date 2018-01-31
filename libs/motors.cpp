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

Motor::Motor(PwmOut *p_pwm, DigitalOut *p_direction0, DigitalOut *p_direction1,
		Qei *p_qei, Pid *p_pid, Ticker *p_ticker)
{
	m_qei_value = 0;
	m_pwm = p_pwm;
	m_direction0 = p_direction0;
	m_direction1 = p_direction1;
	m_qei = p_qei;
	m_pid = p_pid;
	m_ticker = p_ticker;
	m_pwm->period(PERIOD_PWM);
	SetSpeed(0.0f);
	m_ticker->attach(callback(this, &Motor::Refresh), PERIOD_REFRESH);
}

Motor::~Motor()
{
	
}

float Motor::GetSpeed()
{
	return m_PV_speed;
	return m_SP_speed;
}

void Motor::SetSpeed(float speed)
{
	m_SP_speed = speed;
}

void Motor::Refresh()
{
	short dist = RefreshDiff(&m_qei_value, m_qei->GetQei());
	m_PV_speed = (float)dist/PERIOD_REFRESH;
	float duty_cycle = m_pid->GetPid(m_PV_speed - m_SP_speed);
	unsigned char direction_value;
	if (duty_cycle > MIN_DUTY) {
		direction_value = DIRECTION_FORWARD;
	} else if (duty_cycle < -MIN_DUTY) {
		direction_value = DIRECTION_BACKWARD;
		duty_cycle = -duty_cycle;
	} else if (duty_cycle == NAN) {
		direction_value = DIRECTION_BREAK;
	} else {
		direction_value = DIRECTION_STOP;
	}
	SetPwm(duty_cycle, direction_value);
}

void Motor::SetPwm(float duty_cycle, unsigned char direction_value)
{
	if (duty_cycle > MAX_DUTY) {
		duty_cycle = MAX_DUTY;
	}
	m_pwm->write(duty_cycle);
	*m_direction0 = direction_value & 1;
	*m_direction1 = direction_value & 2;
}

