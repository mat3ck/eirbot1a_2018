//
// Created by CopperBot on 20/02/2018.
//

#ifndef GP2_HPP
#define GP2_HPP

#include "mbed.h"

#define COEFF_A (29.967f)
#define COEFF_B (-0.811f)

class Gp2
{
	public:
		Gp2(PinName pin);
		~Gp2();

		AnalogIn GetAnalogIn();
		float GetDistance();
		float GetDistanceMilliMeters();
		void SetThreshold(int distance);
		int IsThresholdReached();

	private:
		AnalogIn analogGP2;
		int threshold;
};

#endif //GP2_H
