/*
 * TODO
 * Add TRESHOLD to nuc_X/config.hpp
 */

#include "gp2.hpp"

Gp2::Gp2(PinName _pin):
	pin(_pin)
{
	threshold = 300.0f;
}

Gp2::~Gp2()
{

}

/* Return the distance in millimeters */
float Gp2::GetDistance()
{
	return (pow((pin.read() / COEF_A), (1.0f / COEF_B)));
}

void Gp2::SetThreshold(int distance)
{
	threshold = distance;
}

int Gp2::IsThresholdReached()
{
	return GetDistance() > threshold;
}
