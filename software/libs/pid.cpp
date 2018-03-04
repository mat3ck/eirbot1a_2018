/*
 * TODO
 * Documentation
 * Make position and angle pid to control motor's speed pid
 * Add Pid::GetPid() to read Pid value without entering new values
 */

#include "pid.hpp"


Pid::Pid(float (&_coef_err)[NB_COEF], float (&_coef_sp)[NB_COEF]):
	coef_err(_coef_err),
	coef_sp(_coef_sp),
	err_ca(NB_COEF),
	sp_ca(NB_COEF)
{
	
}

Pid::~Pid()
{

}

void Pid::Reset()
{
	err_ca.Reset();
	sp_ca.Reset();
}

float Pid::GetPid()
{
	float sum = 0.0f;
	for (int i = 0; i < NB_COEF; i++) {
		sum += coef_err[i] * err_ca[i];
		sum += coef_sp[i] * sp_ca[i];
	}
	return sum;
}

float Pid::GetPid(float err, float sp)
{
	float sum = GetPid();
	RefreshPid(err, sp);
	return sum;
}

void Pid::RefreshPid(float err, float sp)
{
	err_ca.Add(err);
	sp_ca.Add(sp);
}

