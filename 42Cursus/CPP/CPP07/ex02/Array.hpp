#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);

private:
	unsigned int _size;
	T *_arr;

} ;


#endif
