//
// Created by CopperBot on 20/02/2018.
//

#ifndef EIRBOT1A_2018_GP2_H
#define EIRBOT1A_2018_GP2_H

#endif //EIRBOT1A_2018_GP2_H

#include "mbed.h";

class gp2 {

//internals variable of gp2 class
private:

	AnalogIn m_analogGP2;
	int m_threshold;

//Methods of gp2 class
public:

	gp2(PinName pin);
	AnalogIn getAnalogIn();
	float getDistance();
	int getDistanceMilliMeters();
	void setThreshold(int distance);
	int isThresholdReached();
};