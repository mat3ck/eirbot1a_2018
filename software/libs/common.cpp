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

