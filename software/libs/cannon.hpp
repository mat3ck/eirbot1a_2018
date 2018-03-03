//
// Created by CopperBot on 03/03/2018.
//

#ifndef CANNON_H
#define CANNON_H

#include "mbed.h"
#include "Comm_AX12.hpp"
#include "AX12.hpp"

#define STOP 0

class cannon {

	public:
		cannon(PinName rx,PinName tx);
		cannon(PinName rx,PinName tx,char ax12_id);

		void startCannon();
		void stopCannon();
		void setMotorSpeed(short speed,int refreshNow);
		int isBallReady();

	private:
		Comm_AX12 m_comm;
		AX12 m_motor;
		short m_speed;

};




#endif //CANNON_H
