
#ifndef FUNC_HPP
#define FUNC_HPP

#include "navigator.hpp"


#define GREEN 0
#define ORANGE 1

//#define P2_GREEN (Pos(6995.0f, -16177.0f, -3.14f))
#define P1_GREEN (Pos(43000.0f, 0.0f, 0.00f))
#define P2_GREEN (Pos(43000.0f, 0.0f, 1.57f))
#define P3_GREEN (Pos(43000.0f, 10000.0f, 1.57f))

#define P1_ORANGE (Pos(43000.0f, 0.0f, 0.00f))
#define P2_ORANGE (Pos(43000.0f, 0.0f, -1.57f))
#define P3_ORANGE (Pos(43000.0f, -10000.0f, -1.57f))

#define SERVO_INIT (0.090f)
#define SERVO_DEPLOYED (0.038f)
#define BEE_INIT (0.105f)
#define BEE_DEPLOYED (0.070f)

void waitDeparture(DigitalIn& pin);
bool getColor(DigitalIn& pin);
bool waitNav(Navigator& nav, Timer& t, float t_lim);
bool dynamic(Navigator& nav, DigitalIn& key, DigitalIn& mode, PwmOut& servo,
		PwmOut& bee);


#endif

