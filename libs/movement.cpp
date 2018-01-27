/*
 * TODO
 * Documentation
 */


#include "mbed.h"
#include "errors.h"
#include "motors.h"
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


