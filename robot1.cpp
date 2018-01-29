
#include "mbed.h"
#include "errors.h"
#include "pins_robot1.h"
#include "motors.h"
#include "qei.h"
#include "pid_robot1.h"


PwmOut* pwmLeft = new PwmOut(PIN_PWM_LEFT);
DigitalOut* Aleft = new DigitalOut(PIN_DIR_LEFT1);
DigitalOut* Bleft = new DigitalOut(PIN_DIR_LEFT2);

PwmOut* pwmRight = new PwmOut(PIN_PWM_RIGHT);
DigitalOut* Aright = new DigitalOut(PIN_DIR_RIGHT1);
DigitalOut* Bright = new DigitalOut(PIN_DIR_RIGHT2);


int main()
{
}
