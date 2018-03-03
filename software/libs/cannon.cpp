//
// Created by CopperBot on 03/03/2018.
//

#include "cannon.hpp"


cannon::cannon(PinName rx,PinName tx): m_comm(rx,tx), m_motor(&m_comm) {
	m_motor.Init();
	m_speed=45;
}

cannon::cannon(PinName rx,PinName tx,char ax12_id): m_comm(rx,tx), m_motor(&m_comm) {
	m_motor.SetID(ax12_id);
	m_motor.Init();
	m_speed=45;
}

void cannon::startCannon(){
	m_motor.EndlessTurn(1,m_speed);
}

void cannon::stopCannon(){
	m_motor.EndlessTurn(1,STOP);
}

void cannon::setMotorSpeed(short speed,int refreshNow){
	m_speed=speed;
	if (refreshNow)
		m_motor.EndlessTurn(1,m_speed);
}

int cannon::isBallReady(){
	/*
	 * Here, the test to know if the ball is ready to launch.
	 */
	return 1;
}