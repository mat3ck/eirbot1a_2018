
#ifndef PID_ROBOT1_H
#define PID_ROBOT1_H


class Pid {
	public:
		Pid(float, float, float, Timer*);
		~Pid();
		float GetPid(float);
		int SetPid(float, float, float);
	private:
		void RefreshPid(float);
		float m_kp;
		float m_ki;
		float m_kd;
		float m_err;
		float m_ierr;
		float m_derr;
		Timer* m_timer;
};


#endif
