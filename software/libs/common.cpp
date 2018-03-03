/*
 * TODO
 * Documentation
 * Add common macros in common.hpp
 * Add differents length support for CArray
 */

#include "common.hpp"


CArray::CArray()
{
	index = 0;
	for (int i = 0; i < NB_COEF; i++) {
		array[i] = 0.0f;
	}
}

CArray::~CArray()
{

}

void CArray::Reset()
{
	index = 0;
	for (int i = 0; i < NB_COEF; i++) {
		array[i] = 0.0f;
	}
}

void CArray::Add(float val)
{
	index = ((index-1) % NB_COEF + NB_COEF) % NB_COEF;
	array[index] = val;
}

float CArray::operator[](int i)
{
	return array[(index+i) % NB_COEF];
}

