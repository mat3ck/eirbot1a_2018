/*
 * TODO
 * Documentation
 */

#include "common.hpp"


CArray::CArray(int _length)
{
	index = 0;
	length = _length;
	array = new float[length];
	for (int i = 0; i < length; i++) {
		array[i] = 0.0f;
	}
}

CArray::~CArray()
{
	delete [] array;
}

void CArray::Reset()
{
	index = 0;
	for (int i = 0; i < length; i++) {
		array[i] = 0.0f;
	}
}

void CArray::Add(float val)
{
	index = ((index-1) % length + length) % length;
	array[index] = val;
}

float CArray::operator[](int _index)
{
	return array[(index+_index) % length];
}


Pos::Pos()
{
	x = 0.0f;
	y = 0.0f;
	angle = 0.0f;
}

Pos::Pos(float _x, float _y, float _angle)
{
	x = _x;
	y = _y;
	angle = _angle;
}

Pos::~Pos()
{

}

void Pos::Reset()
{
	x = 0.0f;
	y = 0.0f;
	angle = 0.0f;
}


float sg(float val)
{
	return (val < 0.0f) ? -1.0f : 1.0f;
}

float max(float val_1, float val_2)
{
	return (val_1 > val_2) ? val_1 : val_2;
}

float min(float val_1, float val_2)
{
	return (val_1 < val_2) ? val_1 : val_2;
}

float min(float val_1, float val_2, float val_3)
{
	return min(min(val_1, val_2), val_3);
}

float ComputeSpeed(float speed, float dist, float vmax_t, float amax_up,
		float amax_up_t, float amax_down, float amax_down_t)
{
	return sg(dist) * min(abs((float)speed + sg(speed)*amax_up_t),
			      vmax_t,
			      sqrtf(2*amax_down*abs(dist)));
}
