//
// Created by CopperBot on 20/02/2018.
//

#ifndef GP2_HPP
#define GP2_HPP

#include "mbed.h"


#define COEF_A (29.967f)
#define COEF_B (-0.811f)

#define THRESH_GP2 (0.3404f)

class Gp2
{
public:
	Gp2(PinName _pin);
	~Gp2();
	float GetDistance();
	bool ThreshReached();
private:
	float threshold;
	AnalogIn pin;
};

class Gp2Group
{
public:
	Gp2Group(Gp2& _gp2_1, Gp2& _gp2_2, Gp2& _gp2_3, Gp2& _gp2_4);
	~Gp2Group();
	bool Obstacle(int i1, int i2, int i3, int i4);
private:
	Gp2& gp2_1;
	Gp2& gp2_2;
	Gp2& gp2_3;
	Gp2& gp2_4;
};

#endif
