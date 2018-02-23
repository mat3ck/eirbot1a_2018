//
// Created by CopperBot on 20/02/2018.
//

#include "gp2.hpp"

gp2::gp2(PinName pin) : m_analogGP2(pin)
{
	m_threshold = 300;
}

gp2::~gp2()
{

}

AnalogIn gp2::getAnalogIn()
{
	return m_analogGP2;
}

/**
 * Return the distance read with AnalogIn.
 * The more the distance, the more the number (between 0 and 1).
 * @return
 */
float gp2::getDistance()
{
	float distance = 1.0 - m_analogGP2.read();
	return distance;
}

/**
 * Return the distance in millimeters.
 * An approximation of the GP2 output with excel was done to get coefficients "a" and "b".
 * @return
 */
float gp2::getDistanceMilliMeters()
{
	return (pow((m_analogGP2.read() / COEFF_A), (1.0f / COEFF_B)));
}

/**
 * Set the threshold in millimeters.
 * @param distance
 */
void gp2::setThreshold(int distance)
{
	m_threshold = distance;
}

int gp2::isThresholdReached()
{
	if (getDistanceMilliMeters() < m_threshold)
		return 1;
	return 0;
}
