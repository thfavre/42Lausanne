#include "Array.hpp"


template <typename T>
Array<T>::Array()
{
	_arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(int unsigned n)
{
	std::cout << "Array(int unsigned n) constructor" << std::endl;
	_arr = new T[n];
	_size = n;
	std::cout << _size << std::endl;

}

template <typename T>
Array<T>::Array(Array const &array)
{
	_size = array.size();
	_arr = new T[_size];

}


template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &array)
{
	if (this == &array)
		return (*this);
	this->_size = array._size;
	// ! TODO  what to do if size < or > ?
	return (*this);
}

template <typename T>
unsigned int Array<T>::size()
{
	return (_size);
}
