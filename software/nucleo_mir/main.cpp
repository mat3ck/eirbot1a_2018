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
// Qeis
Qei qei_left(ENCODER_TIM_LEFT, err);
Qei qei_right(ENCODER_TIM_RIGHT, err);
// Speed PIDs
Pid pid_left(coef_err, NB_COEF_ERR, coef_sp, NB_COEF_SP);
Pid pid_right(coef_err, NB_COEF_ERR, coef_sp, NB_COEF_SP);
// Motors
Motor motor_left(PWM_L, DIR_L, BREAK_L, DIR_FWD_L, PERIOD_PWM);
Motor motor_right(PWM_R, DIR_R, BREAK_R, DIR_FWD_R, PERIOD_PWM);
// Blocks
Block block_left(qei_left, pid_left, motor_left, MAX_DUTY, PERIOD_PID);
Block block_right(qei_right, pid_right, motor_right, MAX_DUTY, PERIOD_PID);

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

	}
	return 0;
}

