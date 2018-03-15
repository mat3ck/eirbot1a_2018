
#ifndef COMMON_HPP
#define COMMON_HPP


class CArray
{
public:
	CArray(int _length);
	~CArray();
	void Reset();
	void Add(float value);
	float operator[](int _index);
private:
	int index;
	int length;
	float* array;
};

class Pos
{
public:
	Pos();
	Pos(float _x, float _y, float _angle);
	~Pos();
	void Reset();
	float x;
	float y;
	float angle;
};

float sg(float val);
float max(float val_1, float val_2);
float min(float val_1, float val_2);
float min(float val_1, float val_2, float val_3);

#endif

