/*
 * TODO
 */

#include "mbed.h"
#include "telemetry.h"
#include "block.h"

float var_max = 0;
float err_max = 0;
float duty = 0;

void Telemetry(Serial* pc, Block* block)
{
	static float new_duty = block->GetPwm();
	var_max = max(var_max, abs(new_duty-duty));
	duty = new_duty;
	err_max = max(err_max, block->GetPV()-block->GetSP());
	pc->printf("SP\t\tPV\t\tPwm\t\tDir\tVarMax\tErrMax\n\r");
	pc->printf("%f\t%f\t%f\t%d\t%f\t%d\n\r", block->GetSP(), block->GetPV(),
			block->GetPwm(), block->GetDir(), var_max, err_max);
}
