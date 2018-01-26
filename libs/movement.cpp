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

#include "movement.h"
#include "motors.h"

struct s_pos {
	long pos_x;
	long pos_y;
	float angle;
};

bool is_out(struct s_pos pos)
{
	return 0;
}
