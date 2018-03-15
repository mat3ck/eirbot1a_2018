
#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include "mbed.h"
#include "block.hpp"
#include "common.hpp"


class Navigator
{
public:
	Navigator(Block& _block_l, Block& _block_r, float _period);
	~Navigator();
	void Reset();
	void Start();
	Pos GetPos();
	Pos GetDst();
	void SetPos(Pos _pos);
	void SetDst(Pos _dst);
private:
	void Refresh();
	void RefreshPos();
	Pos pos;
	Pos dst;
	short qei_l;
	short qei_r;
	float period;
	Block& block_l;
	Block& block_r;
	Ticker ticker;
};

float ComputeSpeed(short speed, float dist, float vmax_t, float amax,
		float amax_t);

#endif
