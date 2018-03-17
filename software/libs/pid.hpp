
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"
#include "common.hpp"


#define NB_COEF 4

class Pid
{
public:
	Pid(float* _coef_err, int _len_err, float* _coef_sp, int _len_sp);
	~Pid();
	void Reset();
	float GetPid();
	float GetPid(float err, float sp);
private:
	void RefreshPid(float, float);
	float* coef_err;
	int len_err;
	float* coef_sp;
	int len_sp;
	CArray err_ca;
	CArray sp_ca;
};


#endif
