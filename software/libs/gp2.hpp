//
// Created by CopperBot on 20/02/2018.
//

#ifndef EIRBOT1A_2018_GP2_H
#define EIRBOT1A_2018_GP2_H

#include "mbed.h"

#define COEFF_A (29.967f)
#define COEFF_B (-0.811f)

class gp2 {

	public:
		gp2(PinName pin);
		AnalogIn getAnalogIn();
		float getDistance();
		float getDistanceMilliMeters();
		void setThreshold(int distance);
		int isThresholdReached();

		~gp2();

	private:
		AnalogIn m_analogGP2;
		int m_threshold;

};

#endif //EIRBOT1A_2018_GP2_H