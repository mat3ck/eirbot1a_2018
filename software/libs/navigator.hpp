
#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include "mbed.h"
#include "block.hpp"
#include "common.hpp"


const float ticks_per_meter = 43723.0f;
const float eps = 0.318f*ticks_per_meter;
const float vmax = 0.50f*ticks_per_meter;
const float vmax_t = vmax * 0.005f;
const float amax_up = 0.50f*ticks_per_meter;
const float amax_up_t = amax_up*0.005f;
const float amax_down = 0.25f*ticks_per_meter;
const float amax_down_t = amax_down*0.005f;

const float thresh_a = 0.1308f;
const float thresh_a_mov = 0.0087f;
const float thresh_dd = 874.0f;
const float thresh_dd_mov = 218.0f;
const float thresh_ad = 0.0436f;


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

#endif
