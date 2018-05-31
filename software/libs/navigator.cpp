/*
 * TODO
 * Documentation
 * Add all constants in config.hpp
 */

#include "navigator.hpp"


Navigator::Navigator(Block& _block_l, Block& _block_r, Gp2Group& _front_gp2,
		Gp2Group& _back_gp2, float _period, float _period_pos):
	pos(),
	dst(),
	block_l(_block_l),
	block_r(_block_r),
	front_gp2(_front_gp2),
	back_gp2(_back_gp2)
{
	color = 0;
	status = -1;
	obstacle = 0;
	check_obs = 1;
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
	block_l.Pause();
	block_r.Pause();
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

bool Navigator::IsReady()
{
	return (status == 0);
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
	if (abs(err_d) > th_dd) {
		// Corrrect angle to go to dst
		if ((abs(err_a) > th_a_mov && status == 1) ||
				(abs(err_a) > th_a)) {
			status = 1;
			dist_l = -err_a*eps/2.0f;
			dist_r = -dist_l;
		}
		// Arc to go to dst for little angles
		/*
		else if ((abs(err_a) > th_a_mov && status == 2) ||
				(abs(err_a) > th_a_mov)) {
			status = 2;
			float rad = err_d/2.0f/sin(err_a);
			dist_l = (rad-sg(err_a)*eps/2.0f)/2.0f/err_a;
			dist_r = (rad+sg(err_a)*eps/2.0f)/2.0f/err_a;
			float ratio = dist_l/dist_r;
		}
		*/
		// Straight line backward to go to dst
		// /*
		else if (abs(err_a) > th_ab) {
			status = 3;
			dist_l = -err_d;
			dist_r = -err_d;
		}
		// */
		// Straight line forward to go to dst
		else {
			status = 4;
			dist_l = err_d;
			dist_r = err_d;
		}
	} else {
		// Straight line backward to go to dst
		/*
		if ((abs(err_a) > th_ab) ||
				(abs(err_d) > th_dd_mov && status == 4)) {
			status = 4;
			dist_l = err_d;
			dist_r = err_d;
		}
		*/
		// Straight line forward to go to dst
		if (abs(err_d) > th_dd_mov && status == 4) {
			status = 4;
			dist_l = err_d;
			dist_r = err_d;
		}
		// Correct angle to final one
		else if ((abs(err_ad) > th_ad_mov && status == 5) ||
				(abs(err_ad) > th_ad)) {
			status = 5;
			dist_l = -err_ad * eps/2.0f;
			dist_r = -dist_l;
		}
		// No deplacement
		else {
			status = 0;
			dist_l = 0.0f;
			dist_r = 0.0f;
		}
	}
	float speed_l = ComputeSpeed(period, block_l.GetSP(), dist_l, vmax,
				amax_up_t, amax_down_t);
	float speed_r = ComputeSpeed(period, block_l.GetSP(), dist_r, vmax,
				amax_up_t, amax_down_t);
	
	if (check_obs && FrontObstacle()) {
		speed_l = 0.0f;
		speed_r = 0.0f;
	}

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

bool Navigator::FrontObstacle()
{
	return front_gp2.Obstacle(!color, 1, 1, color);
}

bool Navigator::BackObstacle()
{
	return back_gp2.Obstacle(1, 1, 1, 1);
}
