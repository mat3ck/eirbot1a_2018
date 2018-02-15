/*
 * TODO
 */

#include "mbed"
#include "block.h"

float var_max = 0;
float err_max = 0;
float duty = block->GetPwm();

void Telemetry(Serial* pc, Block* block)
{
	var_max = max(var_max, block->GetPwm()-duty);
	err_max = max(err_max, block->GetPV() - block->GetSP());
	pc.printf("SP\tPV\tPwm\tDir\tVarMax\tErrMax\n\r");
	pc.printf("%f\t%f\t%f\t%d\t%d\t%d\n\r", block->GetSP(), block->GetPV(),
			block->GetPwm(), block->GetDir(), var_max, err_max);
}
