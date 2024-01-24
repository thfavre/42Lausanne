#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(Array const &array);

	Array	&operator=(const Array &array);

	unsigned int size();


private:
	unsigned int _size;
	T *_arr;

} ;


#endif
