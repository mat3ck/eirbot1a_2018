
#include "mbed.h"
#include "errors.h"
#include "robot1.h"
#include "qei.h"
#include "pid.h"
#include "motors.h"
#include "block.h"
#include "telemetry.h"


int err = 0;


// Led
DigitalOut led(LED3);
// Serial PC
Serial pc(USBTX, USBRX);
// Left Qei
TIM_Encoder_InitTypeDef* encoder_left = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* htim_left = new TIM_HandleTypeDef;
TIM_TypeDef* TIMx_left = ENCODER_TIM_LEFT;
Qei qei_left(encoder_left, htim_left, TIMx_left, &err);
//Right Qei
TIM_Encoder_InitTypeDef* encoder_right = new TIM_Encoder_InitTypeDef;
TIM_HandleTypeDef* htim_right = new TIM_HandleTypeDef;
TIM_TypeDef* TIMx_right = ENCODER_TIM_RIGHT;
Qei qei_right(encoder_right, htim_right, TIMx_right, &err);
// Left motor speed PID
float coef_err_left[] = {K1_ERR_LEFT, K2_ERR_LEFT, K3_ERR_LEFT};
float coef_sp_left[] = {K1_SP_LEFT, K2_ERR_LEFT, K3_ERR_LEFT};
Pid pid_left(coef_err_left, coef_sp_left);
// Right motor speed PID
float coef_err_right[] = {K1_ERR_RIGHT, K2_ERR_RIGHT, K3_ERR_RIGHT};
float coef_sp_right[] = {K1_SP_RIGHT, K2_ERR_RIGHT, K3_ERR_RIGHT};
Pid pid_right(coef_err_right, coef_sp_right);
// Left Motor
PwmOut* pwm_left = new PwmOut(PIN_PWM_LEFT);
DigitalOut* dir_left = new DigitalOut(PIN_DIR_LEFT);
DigitalOut* break_left = new DigitalOut(PIN_BREAK_LEFT);
Motor motor_left(pwm_left, dir_left, break_left, 0);
// Right Motor
PwmOut* pwm_right = new PwmOut(PIN_PWM_RIGHT);
DigitalOut* dir_right = new DigitalOut(PIN_DIR_RIGHT);
DigitalOut* break_right = new DigitalOut(PIN_BREAK_RIGHT);
Motor motor_right(pwm_right, dir_right, break_right, 1);
// Left Block
Ticker* ticker_left = new Ticker;
Block block_left(&qei_left, &pid_left, &motor_left, ticker_left);
// Right Block
Ticker* ticker_right = new Ticker;
Block block_right(&qei_right, &pid_right, &motor_right, ticker_right);

int main()
{
	starting_led = 1;
	wait(1);
	starting_led = 0;
	pc.printf("\n\n\rStarting, error code : %d\n\r", err);
	while(1) {

	}
}
