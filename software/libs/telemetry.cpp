/*
 * TODO
 */


#include "mbed.h"
#include "telemetry.hpp"
#include "block.hpp"


float var_max = 0.0000f;
float err_max = 0.0000f;
float duty = 0.0000f;
float new_duty = 0.0000f;

void Telemetry(Serial* pc, Block* block)
{
	new_duty = block->GetPwm();
	var_max = max(var_max, abs(new_duty-duty));
	duty = new_duty;
	err_max = max(err_max, abs(block->GetPV()-block->GetSP()));
	pc->printf("SP\t\tPV\t\tPwm\t\tDir\tVarMax\t\tErrMax\n\r");
	pc->printf("%f\t%f\t%f\t%d\t%f\t%f\n\r", block->GetSP(), block->GetPV(),
			block->GetPwm(), block->GetDir(), var_max, err_max);
}
