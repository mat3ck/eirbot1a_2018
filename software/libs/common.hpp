
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


#endif

