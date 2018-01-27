
#include "mbed.h"
#include "pins_robot1.h"
#include "motors.h"


PwmOut* pwmLeft = new PwmOut(PIN_PWM_LEFT);
DigitalOut* Aleft = new DigitalOut(PIN_DIR_LEFT1);
DigitalOut* Bleft = new DigitalOut(PIN_DIR_LEFT2);
struct s_motor motor_left = new_motor(pwmLeft, Aleft, Bleft);

PwmOut* pwmRight = new PwmOut(PIN_PWM_RIGHT);
DigitalOut* Aright = new DigitalOut(PIN_DIR_RIGHT1);
DigitalOut* Bright = new DigitalOut(PIN_DIR_RIGHT2);
struct s_motor motor_right = new_motor(pwmRight, Aright, Bright);


struct s_motor* p_motor_left = &motor_left;
struct s_motor* p_motor_right = &motor_right;


int main()
{
	init_motor(p_motor_left, p_motor_right);
}
