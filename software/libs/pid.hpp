
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"
#include "common.hpp"


#define NB_COEF_ERR 4
#define NB_COEF_SP 3


class Pid
{
public:
	Pid(float(&_coef_err)[NB_COEF_ERR], float (&_coef_sp)[NB_COEF_SP]);
	~Pid();
	void Reset();
	float GetPid();
	float GetPid(float err, float sp);
private:
	void RefreshPid(float, float);
	float (&coef_err)[NB_COEF_ERR];
	float (&coef_sp)[NB_COEF_SP];
	CArray err_ca;
	CArray sp_ca;
};


#endif
