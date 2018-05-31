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

bool dynamic(Navigator& nav, DigitalIn& key, DigitalIn& mode, PwmOut& servo,
		PwmOut& bee)
{
	Timer t;
	servo.write(SERVO_INIT);
	bee.write(BEE_INIT);
	nav.check_obs = 0;
	waitDeparture(key);
	bool color = getColor(mode);
	nav.color = color;
	t.start();
	if (color == ORANGE) {
		printf("Time : %f\r\n", t.read());
		nav.SetDst(P1_ORANGE);
		nav.Start();
		if (waitNav(nav, t, 10.0f)) return 0;
		nav.SetDst(P2_ORANGE);
		nav.check_obs = 0;
		if (waitNav(nav, t, 5.0f)) return 0;
		servo.write(SERVO_DEPLOYED);
		wait(1.0f);
		nav.SetDst(P3_ORANGE);
		if (waitNav(nav, t, 3.0f)) return 0;
		 /*
		nav.SetDst(P4_ORANGE);
		if (waitNav(nav, t, 3.0f)) return 0;
		nav.SetDst(P5_ORANGE);
		servo.write(SERVO_INIT);
		if (waitNav(nav, t, 7.0f)) return 0;
		nav.SetDst(P6_ORANGE);
		if (waitNav(nav, t, 7.0f)) return 0;
		bee.write(BEE_DEPLOYED);
		nav.SetDst(P7_ORANGE);
		if (waitNav(nav, t, 3.0f)) return 0;
		// */
	} else {
		printf("Time : %f\r\n", t.read());
		nav.SetDst(P1_GREEN);
		nav.Start();
		if (waitNav(nav, t, 10.0f)) return 0;
		nav.SetDst(P2_GREEN);
		nav.check_obs = 0;
		if (waitNav(nav, t, 5.0f)) return 0;
		servo.write(SERVO_DEPLOYED);
		wait(1.0f);
		nav.SetDst(P3_GREEN);
		if (waitNav(nav, t, 3.0f)) return 0;
		 /*
		nav.SetDst(P4_GREEN);
		if (waitNav(nav, t, 3.0f)) return 0;
		nav.SetDst(P5_GREEN);
		servo.write(SERVO_INIT);
		if (waitNav(nav, t, 7.0f)) return 0;
		nav.SetDst(P6_GREEN);
		if (waitNav(nav, t, 7.0f)) return 0;
		bee.write(BEE_DEPLOYED);
		nav.SetDst(P7_GREEN);
		if (waitNav(nav, t, 3.0f)) return 0;
		// */
	}
	return 1;
}

