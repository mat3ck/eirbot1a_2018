/*
 * TODO
 * Documentation
 */

#ifndef ERR_INCLUDE
#define ERR_INCLUDE
#include "errors.h"
#endif

#ifndef MBED_INCLUDE
#define MBED_INCLUDE
#include "mbed.h"
#endif

#ifndef MOTORS_INCLUDE
#define MOTORS_INCLUDE
#include "motors.h"
#endif

#include "movement.h"

struct s_pos {
	long pos_x;
	long pos_y;
	float angle;
};

bool is_pos_in(struct s_pos* p_pos)
{
	bool in = 0;
	// in ||= (in an area)
	return in;
}
