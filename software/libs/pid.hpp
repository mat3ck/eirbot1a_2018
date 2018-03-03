
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"
#include "common.hpp"


class Pid
{
	public:
		Pid(float [NB_COEF], float [NB_COEF]);
		~Pid();
		void Reset();
		float GetPid(float, float);
	private:
		void RefreshPid(float, float);
		float* coef_err;
		float* coef_sp;
		CArray* err_ca;
		CArray* sp_ca;
};


#endif
