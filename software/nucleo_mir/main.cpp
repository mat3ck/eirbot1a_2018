/*
 * TODO
 * Documentation
 * Initialization function
 * Rework classes to call them with PinNames
 * Integrate AX12 librarie
 */


#include "mbed.h"
#include "config.hpp"
#include "error.hpp"
#include "telemetry.hpp"
#include "qei.hpp"
#include "motor.hpp"
#include "pid.hpp"
#include "block.hpp"
#include "gp2.hpp"


int err = 0;

float coef_err[] = {K1_ERR, K2_ERR, K3_ERR, K4_ERR};
float coef_sp[] = {K1_SP, K2_SP, K3_SP};

// Led
DigitalOut led(LED3);
// Serial PC
Serial pc(USBTX, USBRX);
// Left Qei
Qei qei_left(ENCODER_TIM_LEFT, err);
//Right Qei
Qei qei_right(ENCODER_TIM_RIGHT, err);
// Left motor speed PID
Pid pid_left(coef_err, 4, coef_sp, 3);
// Right motor speed PID
Pid pid_right(coef_err, 4, coef_sp, 3);
// Left Motor
Motor motor_left(PIN_PWM_LEFT, PIN_DIR_LEFT, PIN_BREAK_LEFT, 0);
// Right Motor
Motor motor_right(PIN_PWM_RIGHT, PIN_DIR_RIGHT, PIN_BREAK_RIGHT, 1);
// Left Block
Block block_left(qei_left, pid_left, motor_left);
// Right Block
Block block_right(qei_right, pid_right, motor_right);

int main()
{
	led = 1;
	pc.baud(115200);
	block_left.Reset();
	block_right.Reset();
	wait(3);
	led = 0;
	pc.printf("\n\n\rStarting, error code : %d\n\r", err);
	while (1) {
		wait(PERIOD_REFRESH);
	}
	return 0;
}

