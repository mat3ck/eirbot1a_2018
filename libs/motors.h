
#ifndef MOTORS_H
#define MOTORS_H

#define PWM_PERIOD 0.000033
#define MAX_DUTY 0.95

#define DIRECTION_STOP 0
#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD 2
#define DIRECTION_BREAK 3


struct s_motor {
	PwmOut* p_pwm;
	DigitalOut* p_direction_0;
	DigitalOut* p_direction_1;
};

struct s_motor new_motor(PwmOut* p_pwm, DigitalOut* p_direction_0, DigitalOut* p_direction_1);
void init_motor(struct s_motor* p_motor_left, struct s_motor* p_motor_right);
int set_pwm(struct s_motor* p_motor, float duty_cycle);
int set_direction(struct s_motor* p_motor, unsigned char direction_value);
void full_stop(struct s_motor* p_motor_left, struct s_motor* p_motor_right);


#endif
