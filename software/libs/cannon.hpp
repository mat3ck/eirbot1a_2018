//
// Created by CopperBot on 03/03/2018.
//

#ifndef CANNON_HPP
#define CANNON_HPP

#include "mbed.h"
#include "Comm_AX12.hpp"
#include "AX12.hpp"

#define STOP 0

class Cannon
{
	public:
		Cannon(PinName rx, PinName tx);
		Cannon(PinName rx, PinName tx, char ax12_id);
		~Cannon();

		void StartCannon();
		void StopCannon();
		void SetMotorSpeed(short speed, int refreshNow);
		int IsBallReady();

	private:
		Comm_AX12 comm;
		AX12 motor;
		short speed;
};

#endif //CANNON_H
