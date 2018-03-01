
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"


#define NB_COEF 3


class CArray {
	public:
		CArray();
		~CArray();
		void Reset();
		void Add(float);
		float operator[](int);
	private:
		int index;
		float array[NB_COEF];
};

class Pid {
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
