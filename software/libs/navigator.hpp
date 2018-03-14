
#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include "mbed.h"
#include "block.hpp"


class Navigator
{
public:
	Navigator(Block& _block_l, Block& _block_r, float _period);
	~Navigator();
	void Reset();
	Pos GetPos();
	Pos GetObj();
	void SetPos(float x, float y, float angle);
	void SetDst(float x, float y, float angle);
private:
	Refresh();
	float pos_x;
	float pos_y;
	float pos_angle;
	float dst_x;
	float dst_y;
	float dst_angle;
	float period;
	Block& block_l;
	Block& block_r;
}


#endif
