/*
 * TODO
 * Documentation
 * Add amax and vmax parameters
 * Add wanted precision values into if block in Refresh()
 */

#include "navigator.hpp"


Navigator::Navigator(Block& _block_l, Block& _block_r, float _period):
	block_l(_block_l),
	block_r(_block_r)
{
	period = _period;
}

Navigator::~Navigator()
{
	
}

Navigator::Reset()
{
	block_l.Reset();
	block_r.Reset();
}

Navigator::GetPos()
{
	
}

Navigator::SetPos(float x, float y, float angle)
{

}

Navigator::SetDst(float x, float y, float angle)
{

}

Navigator::Refresh()
{
	pos_angle += 720*3.141592*(dr - dl)/epsilon;
	float dx = dst_x - pos_x;
	float dy = dst_y - pos_y;
	float dist = sqrt(dx*dx + dy*dy);
	float theta = 2*arctan(dx/(dy+dist))-dst_angle;
	if (abs(theta) > 0) {

	} else if (abs(dist) > 0) {

	} else if ((pos_angle-dst_angle) > 0) {

	} else {
		block_left.SetSpeed(0.0f);
		block_right.SetSpeed(0.0f);
	}
}

