
#ifndef COMMON_HPP
#define COMMON_HPP


#define min(x, y) ((x)<(y) ? (x) : (y))
#define max(x, y) ((x)>(y) ? (x) : (y))


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


#endif

