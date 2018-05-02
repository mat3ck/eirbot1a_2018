
#ifndef REGULATION_HPP
#define REGULATION_HPP

#include "mbed.h"
#include "motor.hpp"
#include "block.hpp"

void openLoopQuadRamp(float pwm_val, float rise_t, float step_t,
		float fall_t);
void closedLoopQuadRamp(float speed_val, float rise_t, float step_t,
		float fall_t);

#endif
