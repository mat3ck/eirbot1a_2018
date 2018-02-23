/*
 * TODO
 * Documentation
 * Make position and angle pid to control motor's speed pid
 * Change GetPid to allow reading value without actualizing arrays
 * Rework constructor to call it with pinNames
 * Move CArray in a common lib and add different length support
 */

#include "mbed.h"
#include "errors.h"
#include "pid.h"


CArray::CArray()
{
	_index = 0;
	for (int i = 0; i < NB_COEF; i++) {
		_array[i] = 0.0f;
	}
}

CArray::~CArray()
{

}

void CArray::Add(float val)
{
	_index = ((_index-1) % NB_COEF + NB_COEF) % NB_COEF;
	_array[_index] = val;
}

float CArray::operator[](int i)
{
	return _array[(_index+i) % NB_COEF];
}

Pid::Pid(float* coef_err, float* coef_sp)
{
	_coef_err = coef_err;
	_coef_sp = coef_sp;
	_err_ca = new CArray();
	_sp_ca = new CArray();
}

Pid::~Pid()
{

}

float Pid::GetPid(float err, float sp)
{
	float sum = 0.0f;
	for (int i = 0; i < NB_COEF; i++) {
		sum += _coef_err[i] * (*_err_ca)[i];
		sum += _coef_sp[i] * (*_sp_ca)[i];
	}
	RefreshPid(err, sp);
	return sum;
}

void Pid::RefreshPid(float err, float sp)
{
	_err_ca->Add(err);
	_sp_ca->Add(sp);
}

