//
// Created by CopperBot on 20/02/2018.
//

#include "gp2.h"


/**
 * Basic contructor of the GP2 object.
 * @param pin
 */
gp2::gp2(PinName pin):
		m_analogGP2(pin){
	//blabla initiate ?
	m_threshold = 300;
}

/**
 * Return the AnalogIn object of the GP2.
 * @return
 */
AnalogIn gp2::getAnalogIn(){
	return m_analogGP2;
}

/**
 * Return the distance read with AnalogIn.
 * The more the distance, the more the number (between 0 and 1).
 * @return
 */
float gp2::getDistance() {
	float distance = 1.0 - m_analogGP2.read();
	return distance;
}

/**
 * Return the distance in millimeters.
 * An approximation of the GP2 output with excel was done to get coefficients "a" and "b".
 * @return
 */
int gp2::getDistanceMilliMeters() {

	float x = m_analogGP2.read();
	float a=29.967;
	float b=-0.811;
	return (int)(pow((x/a),(1.0/b)));
}

/**
 * Set the threshold in millimeters.
 * @param distance
 */
void gp2::setThreshold(int distance){
	m_threshold = distance;
}

/**
 * Get the state of the threshold.
 * @return
 */
int gp2::isThresholdReached() {
	if (getDistanceMilliMeters()<m_threshold)
		return 1;
	return 0;
}