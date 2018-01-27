
/*
 * TODO
 * Documentation
 * Functions to calculate new command, create a pid struct
 * Add xy and angle pid, maybe speed pid for each motor
 */

#include "error.h"
#include "pid_robot1.h"

struct s_pid_coef {
	float kp;
	float ki;
	float kd;
};

int derivate(int pid_err, int pid_previous_err)
{
	return (pid_err - pid_previous_err)/SAMPLING_PERIOD;
}

int integrate(int pid_int, int pid_err)
{
	return pid_int + pid_err*SAMPLING_PERIOD;
}


