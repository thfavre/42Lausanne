#include "Array.hpp"


template <typename T>
Array<T>::Array()
{
	Array(0);
}

template <typename T>
Array<T>::Array(int unsigned n)
{
	_arr = new T[n];
	_size = n;
}

