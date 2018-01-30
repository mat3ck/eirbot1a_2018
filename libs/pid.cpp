
/*
 * TODO
 * Documentation
 * Add xy and angle pid, maybe speed pid for each motor
 */

#include "mbed.h"
#include "errors.h"
#include "pid.h"


Pid::Pid(float kp, float ki, float kd, Timer* p_timer)
{
	m_kp = kp;
	m_ki = ki;
	m_kd = kd;
	m_timer = p_timer;
	m_timer->start();
}

Pid::~Pid()
{

}

float Pid::GetPid(float err)
{
	RefreshPid(err);
	return m_kp*m_err + m_ki*m_ierr + m_kd*m_derr;
}

void Pid::RefreshPid(float err)
{
	float dt = m_timer->read();
	m_timer->reset();
	m_ierr += err*dt;
	m_derr = (err-m_err)/dt;
	m_err = err;
}
