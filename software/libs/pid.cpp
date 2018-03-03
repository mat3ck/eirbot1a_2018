/*
 * TODO
 * Documentation
 * Make position and angle pid to control motor's speed pid
 * Add different length support
 * Add Pid::GetPid() to read Pid value without entering new values
 */

#include "pid.hpp"


Pid::Pid(float* _coef_err, float* _coef_sp, int _length)
{
	coef_err = _coef_err;
	coef_sp = _coef_sp;
	length = _length;
	err_ca = new CArray(length);
	sp_ca = new CArray(length);
}

Pid::~Pid()
{
	delete [] err_ca;
	delete [] sp_ca;
}

void Pid::Reset()
{
	err_ca->Reset();
	sp_ca->Reset();
}

float Pid::GetPid(float err, float sp)
{
	float sum = 0.0f;
	for (int i = 0; i < length; i++) {
		sum += coef_err[i] * (*err_ca)[i];
		sum += coef_sp[i] * (*sp_ca)[i];
	}
	RefreshPid(err, sp);
	return sum;
}

void Pid::RefreshPid(float err, float sp)
{
	err_ca->Add(err);
	sp_ca->Add(sp);
}

