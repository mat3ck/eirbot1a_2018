/*
 * TODO
 *
 *
 */

#include "gp2.hpp"

Gp2::Gp2(PinName pin) : analogGP2(pin)
{
	threshold = 300;
}

Gp2::~Gp2()
{

}

AnalogIn Gp2::GetAnalogIn()
{
	return analogGP2;
}

/**
 * Return the distance read with AnalogIn.
 * The more the distance, the more the number (between 0 and 1).
 * @return
 */
float Gp2::GetDistance()
{
	float distance = 1.0 - analogGP2.read();
	return distance;
}

/**
 * Return the distance in millimeters.
 * An approximation of the GP2 output with excel was done to get coefficients "a" and "b".
 * @return
 */
float Gp2::GetDistanceMilliMeters()
{
	return (pow((analogGP2.read() / COEFF_A), (1.0f / COEFF_B)));
}

/**
 * Set the threshold in millimeters.
 * @param distance
 */
void Gp2::SetThreshold(int distance)
{
	threshold = distance;
}

int Gp2::IsThresholdReached()
{
	if (GetDistanceMilliMeters() < threshold)
		return 1;
	return 0;
}
