/*
 * TODO
 *
 */


#include "mbed.h"


int err = 0;

// Led
DigitalOut led(LED3);
// Serial PC
Serial pc(USBTX, USBRX);


int main()
{
	led = 1;
	pc.baud(115200);
	wait(3);
	led = 0;
	pc.printf("\n\n\rStarting, error code : %d\n\r", err);
	while (1) {
		
	}
}
