
#ifndef REGULATION_HPP
#define REGULATION_HPP

#include "mbed.h"
#include "common.hpp"
#include "motor.hpp"
#include "block.hpp"
#include "navigator.hpp"

void openLoopQuadRamp(float pwm_val, float rise_t, float step_t,
		float fall_t);
void closedLoopQuadRamp(Block block_l, Block block_r, float speed_val,
		float rise_t, float step_t, float fall_t, float sample_t);
void distQuadRamp(Block block_l, Block block_r, float dist, float sample_t,
		float vmax, float amax_up, float amax_up_t, float amax_down,
		float amax_down_t);

#endif
