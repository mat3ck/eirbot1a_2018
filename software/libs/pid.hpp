
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"
#include "common.hpp"


class Pid
{
	public:
		Pid(float* _coef_err, float* _coef_sp, int _length);
		~Pid();
		void Reset();
		float GetPid(float err, float sp);
		float GetPid();
	private:
		void RefreshPid(float, float);
		int length;
		float* coef_err;
		float* coef_sp;
		CArray* err_ca;
		CArray* sp_ca;
};


#endif
