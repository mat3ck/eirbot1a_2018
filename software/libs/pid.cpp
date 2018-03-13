/*
 * TODO
 * Documentation
 * Make position and angle pid to control motor's speed pid
 */

#include "pid.hpp"


Pid::Pid(float* _coef_err, int _len_err, float* _coef_sp, int _len_sp):
	err_ca(_len_err),
	sp_ca(_len_sp)
{
	coef_err = _coef_err;
	coef_sp = _coef_sp;
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
	for (int i = 0; i < _len_err; i++) {
		sum += coef_err[i] * err_ca[i];
	}
	for (int i = 0; i < _len_sp; i++) {
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

