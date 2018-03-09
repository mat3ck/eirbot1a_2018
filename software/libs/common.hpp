
#ifndef COMMON_HPP
#define COMMON_HPP


float sg(float val);
float max(float val_1, float val_2);
float min(float val_1, float val_2);
float min(float val_1, float val_2, float val_3);

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

