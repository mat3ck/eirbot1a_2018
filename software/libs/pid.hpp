
#ifndef PID_HPP
#define PID_HPP

#include "mbed.h"


#define NB_COEF 3


class CArray {
	public:
		CArray();
		~CArray();
		void Add(float);
		float operator[](int);
	private:
		int _index;
		float _array[NB_COEF];
};

class Pid {
	public:
		Pid(float [NB_COEF], float [NB_COEF]);
		~Pid();
		float GetPid(float, float);
	private:
		void RefreshPid(float, float);
		float* _coef_err;
		float* _coef_sp;
		CArray* _err_ca;
		CArray* _sp_ca;
};


#endif
