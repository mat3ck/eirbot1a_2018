/*
 * TODO
 * setup "IsBallReady()" function.
 *
 */

#include "cannon.hpp"

Cannon::Cannon(PinName rx, PinName tx) : comm(rx, tx), motor(&comm)
{
	motor.Init();
	speed = 45;
}

Cannon::~Cannon()
{

}

Cannon::Cannon(PinName rx, PinName tx, char ax12_id) : comm(rx, tx), motor(&comm)
{
	motor.SetID(ax12_id);
	motor.Init();
	speed = 45;
}

void Cannon::StartCannon()
{
	motor.EndlessTurn(1, speed);
}

void Cannon::StopCannon()
{
	motor.EndlessTurn(1, STOP);
}

void Cannon::SetMotorSpeed(short speed, int refreshNow)
{
	speed = speed;
	if (refreshNow)
		motor.EndlessTurn(1, speed);
}

int Cannon::IsBallReady()
{
	/*
	 * Here, the test to know if the ball is ready to launch.
	 */
	return 1;
}