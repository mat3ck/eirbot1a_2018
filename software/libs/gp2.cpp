/*
 * TODO
 * Add TRESHOLD to nuc_X/config.hpp
 */

#include "gp2.hpp"

Gp2::Gp2(PinName _pin):
	pin(_pin)
{
	threshold = THRESH_GP2;
}

Gp2::~Gp2()
{

}

/* Return the distance in millimeters */
float Gp2::GetDistance()
{
	return (pow((pin.read() / COEF_A), (1.0f / COEF_B)));
}

bool Gp2::ThreshReached()
{
	return pin.read() > threshold;
}

Gp2Group::Gp2Group(Gp2& _gp2_1, Gp2& _gp2_2, Gp2& _gp2_3, Gp2& _gp2_4):
	gp2_1(_gp2_1),
	gp2_2(_gp2_2),
	gp2_3(_gp2_3),
	gp2_4(_gp2_4)
{
	
}


Gp2Group::~Gp2Group()
{

}

bool Gp2Group::Obstacle(int i1, int i2, int i3, int i4)
{
	return ((gp2_1.ThreshReached() && i1 ) ||
			(gp2_2.ThreshReached() && i2 )||
			(gp2_3.ThreshReached() && i3 )||
			(gp2_4.ThreshReached() && i4));
}


