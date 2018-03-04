//
// Created by CopperBot on 20/02/2018.
//

#ifndef GP2_HPP
#define GP2_HPP

#include "mbed.h"


#define COEF_A (29.967f)
#define COEF_B (-0.811f)

class Gp2
{
public:
	Gp2(PinName _pin);
	~Gp2();
	float GetDistance();
	void SetThreshold(int distance);
	int IsThresholdReached();
private:
	float threshold;
	AnalogIn pin;
};


#endif
