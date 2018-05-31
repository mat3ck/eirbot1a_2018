/*
 * TODO
 * Documentation
 * Integrate AX12 librarie
 */


#include "mbed.h"
#include "config.hpp"
#include "error.hpp"
#include "qei.hpp"
#include "motor.hpp"
#include "pid.hpp"
#include "block.hpp"
#include "navigator.hpp"
#include "gp2.hpp"
#include "func.hpp"


int err = 0;

float coef_err_l[] = {K1_ERR_L, K2_ERR_L, K3_ERR_L};
float coef_sp_l[] = {K1_SP_L, K2_SP_L, K3_SP_L};
float coef_err_r[] = {K1_ERR_R, K2_ERR_R, K3_ERR_R};
float coef_sp_r[] = {K1_SP_R, K2_SP_R, K3_SP_R};

// Led
DigitalOut led(LED3);
DigitalOut led_end(LED2);
// Serial PC
Serial pc(USBTX, USBRX);
Serial afficheur(PC_12, PD_2);
// Qeis
Qei qei_l(ENCODER_TIM_LEFT, err, MIR);
Qei qei_r(ENCODER_TIM_RIGHT, err, MIR);
// Speed PIDs
Pid pid_l(coef_err_l, NB_COEF_ERR, coef_sp_l, NB_COEF_SP);
Pid pid_r(coef_err_r, NB_COEF_ERR, coef_sp_r, NB_COEF_SP);
// Motors
Motor motor_l(PWM_L, DIR_L, BREAK_L, DIR_FWD_L, PERIOD_PWM);
Motor motor_r(PWM_R, DIR_R, BREAK_R, DIR_FWD_R, PERIOD_PWM);
// Blocks
Block block_l(qei_l, pid_l, motor_l, MAX_DUTY, PERIOD_PID);
Block block_r(qei_r, pid_r, motor_r, MAX_DUTY, PERIOD_PID);
// GP2
Gp2 gp2_cl(PF_8);
Gp2 gp2_cr(PF_7);
Gp2 gp2_l(PF_10);
Gp2 gp2_r(PF_5);
Gp2Group front_gp2(gp2_cl, gp2_cr, gp2_cl, gp2_cr);
Gp2 gp2_b(PF_5);
Gp2Group back_gp2(gp2_b, gp2_b, gp2_b, gp2_b);
// Navigator
Navigator navigator(block_l, block_r, front_gp2, back_gp2, PERIOD_PID, PERIOD_POS);
// Key
DigitalIn key(PB_9);
// Mode
DigitalIn color_mode(PB_8);
// Servo
PwmOut servo(PE_5);
PwmOut bee(PF_9);


int main()
{
	led = 1;
	pc.baud(115200);
	afficheur.baud(9600);
	key.mode(PullUp);
	servo.period(0.02f);
	bee.period(0.02f);
	pc.printf("\n\n\rStarting, error code : %d\n\r", err);
	char c;
	char state = 'P';
	Pos pos = navigator.GetPos();
	afficheur.printf("010");
	wait(3);
	led = 0;
	/*
	navigator.Reset();
	navigator.SetDst(Pos(0.0f, 0.0f, 0.0f));
	navigator.Start();
	navigator.Pause();
	led = 0;
	while (1) {
		if (pc.readable()) {
			c = pc.getc();
			if (c == 'q') {
				navigator.Pause();
				state = 'P';
			} else if (c == 's') {
				navigator.Unpause();
				state = 'S';
			} else if (c == 'R') {
				navigator.Reset();
				state = 'P';
			}
		}
		pos = navigator.GetPos();
		pc.printf("%c\t%f\t%f\t%f\r", state, pos.x, pos.y, pos.angle);
	}
	*/
	afficheur.printf("035");
	dynamic(navigator, key, color_mode, servo, bee);
	navigator.Reset();
	led_end = 1;
	return 0;
}

