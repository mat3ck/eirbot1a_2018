#include "mbed.h"

#define CLK_REFRESH 5
#define NO_ERROR 0
#define ERR_COM_BAD_STATE 10
#define ERR_RECEPTION_PROCESS 20
#define ERR_RECEPTION_INIT 21
#define ERR_RECEPTION_CLOSURE 22
#define ERR_RECEPTION_TIMEOUT 29
#define ERR_SEND_INIT 31
#define ERR_SEND_CLOSURE 32
#define ERR_SEND_REQUEST 33
#define ERR_SEND_TIMEOUT 39

Serial pc(USBTX, USBRX);
DigitalIn in_data(D5);
DigitalIn in_clk(D3);
DigitalOut out_data(D10);
DigitalOut out_clk(D6);
Timer t_com;
Timer t_global;

bool receive_request(unsigned char *err)
{
	if (in_data && !in_clk) *err = ERR_COM_BAD_STATE;
	return !in_data && !in_clk;
}

bool receive_bit(unsigned char *err)
{
	t_com.start();
	while (in_clk) {
		if (t_com.read_us() > 100) {
			*err = ERR_RECEPTION_TIMEOUT;
			return 0;
		}
		wait_us(CLK_REFRESH);
	}
	bool in = in_data;
	t_com.reset();
	while (!in_clk) {
		if (t_com.read_us() > 100) {
			*err = ERR_RECEPTION_TIMEOUT;
			return 0;
		}
		wait_us(CLK_REFRESH);
	}
	t_com.stop();
	t_com.reset();
	return in;
}

unsigned char receive_data(unsigned char *err)
{
	unsigned char in = 0;
	bool bit = receive_bit(err);
	if (bit) {
		*err = ERR_RECEPTION_INIT;
		return 0;
	} else if (*err) return 0;
	for (int i = 0; i < 8; i++) {
		bit = receive_bit(err);
		if (*err) return 0;
		in >>= 1;
		in |= bit*128;
	}
	bit = receive_bit(err);
	if (*err) return 0;
	bit = receive_bit(err);
	if (bit) {
		*err = ERR_RECEPTION_CLOSURE;
		return 0;
	} else if (*err) return 0;
	wait_us(CLK_REFRESH/2);
	return in;
}

bool send_request(unsigned char *err)
{
	t_com.start();
	out_clk = 1;
	while (t_com.read_us() < 150) {
		if (not(in_data)) {
			*err = ERR_SEND_REQUEST;
			return 0;
		}
	}
	out_data = 0;
	wait_us(10);
	out_clk = 0;
	t_com.stop();
	t_com.reset();
	return 1;
}

bool send_bit(bool bit, unsigned char *err)
{
	t_com.reset();
	t_com.start();
	while (in_clk) {
		if (t_com.read_us() > 150) {
			pc.printf("a");
			*err = ERR_SEND_TIMEOUT;
			return 0;
		}
		wait_us(CLK_REFRESH);
	}
	out_data = bit;
	t_com.reset();
	while (!in_clk) {
		if (t_com.read_us() > 150) {
			pc.printf("b");
			*err = ERR_SEND_TIMEOUT;
			return 0;
		}
		wait_us(CLK_REFRESH);
	}
	t_com.stop();
	t_com.reset();
	return 1;
}

bool send(int hex, unsigned char *err)
{
	bool out  = 0;
	bool parity = 0;
	for (int j = 0; j < 8; j++) {
		out = 1 && (hex & 128);
		parity += out;
		hex <<= 1;
		send_bit(out, err);
		if (*err) return 0;
	}
	send_bit(parity, err);
	send_bit(1, err);
	bool ack = receive_bit(err);
	if (ack) *err = ERR_SEND_CLOSURE;
	return 1;
}

void print_byte(char *byte)
{
	pc.printf("%d\t", *byte);
	char mask = 128;
	for (int i = 0; i < 8; i++) {
		pc.printf("%d", *byte & mask);
		mask >>= 1;
	}
	pc.printf("\n\r");
}

/*
int main() {
	unsigned char err;
	out_clk = 0;
	out_data = 0;
	bool dth = 0;
	bool htd = 0;
	bool init = 0;
	wait_us(1000);
	pc.printf("Starting : \n\r");
	while (not(init)) {
		if (send_request(&err)) init = send(0xF4, &err);
		pc.printf("Initialisation : %d, erreur : %d\n\r", init, err);
		wait_us(200);
	}
} */
