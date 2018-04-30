/*
 * TODO
 * Documentation
 * Add all constants in config.hpp
 */

#include "navigator.hpp"

float ticks_per_meter = 43723.0f;
float eps = 0.318f*ticks_per_meter;
float vmax = 0.15f*ticks_per_meter;
float vmax_t = vmax * 0.0052f;
float amax_up = 0.04f*ticks_per_meter;
float amax_up_t = amax_up*0.0052f;
float amax_down = 0.0001f*ticks_per_meter;
float amax_down_t = amax_down*0.0052f;

float thresh_a = 0.1308f;
float thresh_a_mov = 0.0087f;
float thresh_dd = 874.0f;
float thresh_dd_mov = 218.0f;
float thresh_ad = 0.0436f;
float thresh_ad_mov = 0.0087f;


Navigator::Navigator(Block& _block_l, Block& _block_r, float _period,
		float _period_pos):
	pos(),
	dst(),
	block_l(_block_l),
	block_r(_block_r)
{
	qei_l = 0;
	qei_r = 0;
	period = _period;
	period_pos = _period_pos;
}

Navigator::~Navigator()
{
	
}

void Navigator::Reset()
{
	ticker.detach();
	ticker_pos.detach();
	block_l.Reset();
	block_r.Reset();
	qei_l = 0;
	qei_r = 0;
}

void Navigator::Start()
{
	block_l.Start();
	block_r.Start();
	ticker.attach(callback(this, &Navigator::Refresh), period);
	ticker_pos.attach(callback(this, &Navigator::RefreshPos), period_pos);
}

void Navigator::Pause()
{
	ticker.detach();
	block_l.Reset();
	block_r.Reset();
	qei_l = 0;
	qei_r = 0;
}

void Navigator::Unpause()
{
	ticker.attach(callback(this, &Navigator::Refresh), period);
}

Pos Navigator::GetPos()
{
	return pos;
}

Pos Navigator::GetDst()
{
	return dst;
}

void Navigator::SetPos(Pos _pos)
{

}

void Navigator::SetDst(Pos _dst)
{
	dst.x = _dst.x;
	dst.y = _dst.y;
	dst.angle = _dst.angle;
}

void Navigator::Refresh()
{
	unsigned char status = 0;
	float dx = dst.x - pos.x;
	float dy = dst.y - pos.y;
	// Dist error
	float err_d = sqrtf(dx*dx + dy*dy);
	// Angle error to go to dst
	float err_a = 2.0f * atan(dy/(dx+err_d)) - pos.angle;
	// Dst angle error
	float err_ad = dst.angle - pos.angle;
	float dist_l = 0.0f;
	float dist_r = 0.0f;
	if (abs(err_d) > thresh_dd) {
		// Corrrect angle to go to dst
		if ((abs(err_a) > thresh_a_mov && status == 1) ||
				(abs(err_a) > thresh_a)) {
			status = 1;
			dist_l = -err_a*eps/2.0f;
			dist_r = -dist_l;
		}
		// Arc to go to dst for little angles
		else if ((abs(err_a) > thresh_a_mov && status == 2) ||
				(abs(err_a) > thresh_a_mov)) {
			status = 2;
			float rad = err_d/2.0f/sin(err_a);
			dist_l = (rad-sg(err_a)*eps/2.0f)/2.0f/err_a;
			dist_r = (rad+sg(err_a)*eps/2.0f)/2.0f/err_a;
		}
		// Straight line forward to go to dst
		else {
			status = 3;
			dist_l = err_d;
			dist_r = err_d;
		}
	} else {
		// Straight line forward to go to dst
		if (abs(err_d) > thresh_dd_mov && status == 3) {
			status = 3;
			dist_l = err_d;
			dist_r = err_d;
		}
		// Correct angle to final one
		else if ((abs(err_ad) > thresh_ad_mov && status == 4) ||
				(abs(err_a) > thresh_ad)) {
			status = 4;
			dist_l = -err_ad * eps/2.0f;
			dist_r = -dist_l;
		}
		// No deplacement
		else {
			status = 0;
		}
	}
	float speed_l = ComputeSpeed(block_l.GetPV(), dist_l, vmax, amax_up,
				amax_up_t, amax_down, amax_down_t);
	float speed_r = ComputeSpeed(block_l.GetPV(), dist_r, vmax, amax_up,
				amax_up_t, amax_down, amax_down_t);
	block_l.SetSpeed(speed_l);
	block_r.SetSpeed(speed_r);
	block_l.Refresh();
	block_r.Refresh();
}

void Navigator::RefreshPos()
{
	float dl = (float)block_l.GetQei(qei_l);
	float dr = (float)block_r.GetQei(qei_r);
	float angle = (dr-dl)/eps;
	float dx = (dl+dr)/2.0f;
	float dy = 0.0f;
	if (abs(angle) > 0.0000175f) {
		float radius = (dl+dr)/2.0f/angle;
		dx = radius*sin(angle);
		dy = radius*(1.0f-cos(angle));
	}
	pos.x += cos(pos.angle)*dx - sin(pos.angle)*dy;
	pos.y += sin(pos.angle)*dx + cos(pos.angle)*dy;
	pos.angle += angle;
	if (abs(pos.angle) > PI) pos.angle -= sg(pos.angle)*TWOPI;
}


float ComputeSpeed(float speed, float dist, float vmax_t, float amax_up,
		float amax_up_t, float amax_down, float amax_down_t)
{
	return sg(dist) * min(abs((float)speed + sg(speed)*amax_up_t),
			      vmax_t,
			      sqrtf(2*amax_down*abs(dist)));
}

