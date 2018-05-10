
#ifndef FUNC_HPP
#define FUNC_HPP

#include "navigator.hpp"


#define GREEN 0
#define ORANGE 1

#define P_INIT_GREEN (Pos(9006.9f, -59638.1f, 1.57f))
#define P_INIT_ORANGE (Pos(9006.9f, 59638.1f, -1.57f))

#define P1_GREEN (Pos(9006.9f, -16177.0f, -3.14f))
#define P2_GREEN (Pos(6995.0f, -16177.0f, -3.14f))
#define P1_ORANGE (Pos(9006.9f, 16177.0f, -3.14f))
#define P2_ORANGE (Pos(6995.0f, 16177.0f, -3.14f))

#define SERVO_INIT (0.090f)
#define SERVO_DEPLOYED (0.038f)

void waitDeparture(DigitalIn& pin);
bool getColor(DigitalIn& pin);
bool waitNav(Navigator& nav, Timer& t, float t_lim);
bool dynamic(Navigator& nav, DigitalIn& key, DigitalIn& mode, PwmOut& servo);


#endif

