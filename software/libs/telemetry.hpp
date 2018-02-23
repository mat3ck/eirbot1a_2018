
#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "mbed.h"
#include "block.hpp"


#define max(x, y) ((x)>(y) ? (x) : (y))

void Telemetry(Serial*, Block*);


#endif
