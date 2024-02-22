
#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"


template <typename T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(int unsigned n)
{
	std::cout << "Array(int unsigned n) constructor, with size : " << n << std::endl;
	_arr = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array<T> &array)
{
	_size = array.size();
	_arr = new T[_size];
	for (unsigned int i=0; i<_size; i++)
		_arr[i] = array[i];

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
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int i) const
{
	if(i >= (int)_size || i < 0)
		throw (IndexOutOfBoundsException());
	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}


#endif // ARRAY_TPP
