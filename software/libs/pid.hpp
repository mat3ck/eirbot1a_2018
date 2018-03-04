
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"
#include "common.hpp"


#define NB_COEF 3


class Pid
{
public:
	Pid(float(&_coef_err)[NB_COEF], float (&_coef_sp)[NB_COEF]);
	~Pid();
	void Reset();
	float GetPid();
	float GetPid(float err, float sp);
private:
	void RefreshPid(float, float);
	float (&coef_err)[NB_COEF];
	float (&coef_sp)[NB_COEF];
	CArray err_ca;
	CArray sp_ca;
};


#endif
