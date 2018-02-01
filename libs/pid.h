
#ifndef PID_ROBOT1_H
#define PID_ROBOT1_H

#include "mbed.h"

class Pid {
	public:
		Pid(float, float, float, Timer*);
		~Pid();
		float GetPid(float);
	protected:
		int SetPid(float, float, float);
	private:
		void RefreshPid(float);
		float _kp;
		float _ki;
		float _kd;
		float _err;
		float _ierr;
		float _derr;
		Timer* _timer;
};


#endif
