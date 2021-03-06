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


// Led
DigitalOut led(LED3);
// Serial PC
Serial pc(USBTX, USBRX);
// Left Qei
Qei qei_left(ENCODER_TIM_LEFT, err);
//Right Qei
Qei qei_right(ENCODER_TIM_RIGHT, err);
// Left motor speed PID
float coef_err_left[] = {K1_ERR_LEFT, K2_ERR_LEFT, K3_ERR_LEFT, K4_ERR_LEFT};
float coef_sp_left[] = {K1_SP_LEFT, K2_SP_LEFT, K3_SP_LEFT};
Pid pid_left(coef_err_left, coef_sp_left);
// Right motor speed PID
float coef_err_right[] = {K1_ERR_RIGHT, K2_ERR_RIGHT, K3_ERR_RIGHT, K4_ERR_RIGHT};
float coef_sp_right[] = {K1_SP_RIGHT, K2_SP_RIGHT, K3_SP_RIGHT};
Pid pid_right(coef_err_right, coef_sp_right);
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
	float vmax = 90.5f;
	float a = 3996.0f;
	float at = 20.3f;
	wait(3);
	led = 0;
	pc.printf("\n\n\rStarting, error code : %d\n\r", err);
	block_left.Start();
	block_right.Start();
	int d_left = 42622;
	short qei_l = block_left.GetQei();
	int d_right = 42622;
	short qei_r = block_right.GetQei();
	while (1) {
		printf("%f\t%f\t%d\t%d\r", block_left.GetPV(), block_right.GetPV(),
				d_left, d_right);
		d_left -= block_left.GetQei(&qei_l);
		d_right -= block_right.GetQei(&qei_r);
		block_left.SetSpeed(min(block_left.GetPV() + at,
					vmax,
					sqrtf(2*a*abs(d_left))));
		block_right.SetSpeed(min(block_right.GetPV() + at,
					 vmax,
					 sqrtf(2*a*abs(d_right))));
		if (d_left < 5000) {
			block_left.Reset();
		}
		if (d_right < 5000) {
			block_right.Reset();
		}
		wait(PERIOD_REFRESH);
	}
	return 0;
}

