/* TODO
 * Documentation
 * Add open loop and closed loop quaad ramp functions to test regulation
 */

#include "regulation.hpp"

void openLoopQuadRamp(float pwm_val, float rise_t, float step_t,
		float fall_t, float sample_t) {

}

void closedLoopQuadRamp(Block block_l, Block block_r, float speed_val,
		float rise_t, float step_t, float fall_t, float sample_t) {
	Timer t;
	float speed = 0.0f;
	float PV_l = 0.0f;
	float PV_r = 0.0f;
	short qei_l = block_l.GetQei();
	short qei_r = block_r.GetQei();
	t.start();
	printf("%f\t%f\t%f\t%f\n\r", t.read(), speed, PV_l, PV_r);
	float i = t.read();
	while (t.read() < rise_t) {
		while (t.read()-i < sample_t);
		i = t.read();
		PV_l = block_l.GetQei(qei_l);
		PV_r = block_r.GetQei(qei_r);
		printf("%f\t%f\t%f\t%f\n\r", t.read(), speed, PV_l, PV_r);
		speed = speed_val * i / rise_t;
		block_l.SetSpeed(speed);
		block_r.SetSpeed(speed);
		block_l.Refresh();
		block_r.Refresh();
	}
	t.reset();
	i = t.read();
	while (t.read() < rise_t) {
		while (t.read()-i < sample_t);
		i = t.read();
		PV_l = block_l.GetQei(qei_l);
		PV_r = block_r.GetQei(qei_r);
		printf("%f\t%f\t%f\t%f\n\r", t.read(), speed, PV_l, PV_r);
		block_l.Refresh();
		block_r.Refresh();
	}
	t.reset();
	i = t.read();
	while (t.read() < rise_t) {
		while (t.read()-i < sample_t);
		i = t.read();
		PV_l = block_l.GetQei(qei_l);
		PV_r = block_r.GetQei(qei_r);
		printf("%f\t%f\t%f\t%f\n\r", t.read(), speed, PV_l, PV_r);
		speed = speed_val * (1 - i / fall_t);
		block_l.SetSpeed(speed);
		block_r.SetSpeed(speed);
		block_l.Refresh();
		block_r.Refresh();
	}
	block_l.Reset();
	block_r.Reset();
}

