/*
 * TODO
 * Documentation
 */

#include "func.hpp"


void waitDeparture(DigitalIn& key)
{
	while (key == 0);
}

bool getColor(DigitalIn& mode)
{
	return (mode);
}

bool waitNav(Navigator& nav, Timer& t, float t_lim)
{
	Timer t_over;
	t_over.start();
	while (1)
	{
		if (t.read() > 98.0f) return 1;
		if (nav.obstacle) t_over.reset();
		if (nav.IsReady() || t_over > t_lim) return 0;
	}
}

bool dynamic(Navigator& nav, DigitalIn& key, DigitalIn& mode, PwmOut& servo)
{
	Timer t;
	waitDeparture(key);
	bool color = getColor(mode);
	t.start();
	nav.Start();
	if (color == ORANGE) {
		nav.SetPos(P_INIT_ORANGE);
		nav.SetDst(P1_ORANGE);
		if (waitNav(nav, t, 10.0f)) return 0;
		servo.write(SERVO_DEPLOYED);
		nav.SetDst(P2_ORANGE);
		if (waitNav(nav, t, 5.0f)) return 0;
	} else {
		nav.SetPos(P_INIT_GREEN);
		nav.SetDst(P1_GREEN);
		if (waitNav(nav, t, 10.0f)) return 0;
		servo.write(SERVO_DEPLOYED);
		nav.SetDst(P2_GREEN);
		if (waitNav(nav, t, 5.0f)) return 0;
	}
	return 1;
}
