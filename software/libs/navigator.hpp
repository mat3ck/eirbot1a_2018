
#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include "mbed.h"
#include "common.hpp"
#include "block.hpp"
#include "gp2.hpp"


const float ticks_per_meter = 43723.0f;
const float eps = 0.318f*ticks_per_meter;
const float vmax = 0.50f*ticks_per_meter;
const float vmax_t = vmax * 0.005f;
const float amax_up = 0.75f*ticks_per_meter;
const float amax_up_t = amax_up*0.005f;
const float amax_down = 0.15f*ticks_per_meter;
const float amax_down_t = amax_down*0.005f;

const float th_a = 30 * PI / 360.0f;
const float th_a_mov = 1 * PI / 360.0f;
const float th_dd = 0.03 * ticks_per_meter;
const float th_dd_mov = 0.01 * ticks_per_meter;
const float th_ad = 3 * PI / 360.0f;
const float th_ad_mov = 1 * PI / 360.0f;
const float th_ab = 170 * PI / 360;


class Navigator
{
public:
	Navigator(Block& _block_l, Block& _block_r, Gp2Group& front_gp2,
			Gp2Group& back_gp2, float _period, float _period_pos);
	~Navigator();
	void Reset();
	void Pause();
	void Unpause();
	void Start();
	Pos GetPos();
	Pos GetDst();
	void SetPos(Pos _pos);
	void SetDst(Pos _dst);
	bool IsReady();
	bool obstacle;
	bool check_obs;
	bool color;
private:
	void Refresh();
	void RefreshPos();
	bool FrontObstacle();
	bool BackObstacle();
	Pos pos;
	Pos dst;
	short status;
	short qei_l;
	short qei_r;
	float period;
	float period_pos;
	Block& block_l;
	Block& block_r;
	Gp2Group& front_gp2;
	Gp2Group& back_gp2;
	Ticker ticker;
	Ticker ticker_pos;
};

#endif
