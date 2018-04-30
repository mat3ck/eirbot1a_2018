
#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include "mbed.h"
#include "block.hpp"
#include "common.hpp"


class Navigator
{
public:
	Navigator(Block& _block_l, Block& _block_r, float _period,
			float _period_pos);
	~Navigator();
	void Reset();
	void Pause();
	void Unpause();
	void Start();
	Pos GetPos();
	Pos GetDst();
	void SetPos(Pos _pos);
	void SetDst(Pos _dst);
	void RefreshPos();
private:
	void Refresh();
	Pos pos;
	Pos dst;
	short qei_l;
	short qei_r;
	float period;
	float period_pos;
	Block& block_l;
	Block& block_r;
	Ticker ticker;
	Ticker ticker_pos;
};

float ComputeSpeed(float speed, float dist, float vmax_t, float amax_up,
		float amax_up_t, float amax_down, float amax_down_t);

#endif
