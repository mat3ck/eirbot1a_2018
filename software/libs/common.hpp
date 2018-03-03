
#ifndef COMMON_HPP
#define COMMON_HPP


#define NB_COEF 3


class CArray
{
	public:
		CArray();
		~CArray();
		void Reset();
		void Add(float);
		float operator[](int);
	private:
		int index;
		float array[NB_COEF];
};


#endif

