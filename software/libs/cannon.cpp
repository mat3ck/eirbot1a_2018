/*
 * TODO
 * Documentation
 * Setup "IsBallReady()" function.
 */

#include "cannon.hpp"


Cannon::Cannon(PinName rx, PinName tx):
	ax12_comm(rx, tx), ax12(&ax12_comm)
{
	ax12.Init();
	speed = 45;
}

Cannon::Cannon(PinName rx, PinName tx, char ax12_id):
	ax12_comm(rx, tx), ax12(&ax12_comm)
{
	ax12.SetID(ax12_id);
	ax12.Init();
	speed = 45;
}

Cannon::~Cannon()
{

}

void Cannon::Start()
{
	ax12.EndlessTurn(1, speed);
}

void Cannon::Stop()
{
	ax12.EndlessTurn(1, STOP);
}

void Cannon::SetMotorSpeed(short speed, bool refreshNow)
{
	speed = speed;
	if (refreshNow) {
		ax12.EndlessTurn(1, speed);
	}
}

bool Cannon::IsBallReady()
{
	// Insert the test to know if the ball is ready to launch.
	return 1;
}

